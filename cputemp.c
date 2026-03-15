#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // sleep()

void read_temps(void) {
    FILE *fp;
    char path[256];
    char label[64];
    int temp;

    printf("\033[2J\033[H");   // clear screen + move cursor to top
    printf("=== CPU Temperatures ===\n\n");

    for (int hwmon = 0; hwmon < 10; hwmon++) {
        for (int sensor = 1; sensor < 10; sensor++) {

            snprintf(path, sizeof(path),
                "/sys/class/hwmon/hwmon%d/temp%d_label", hwmon, sensor);
            fp = fopen(path, "r");
            if (fp) {
                fgets(label, sizeof(label), fp);
                label[strcspn(label, "\n")] = '\0';
                fclose(fp);
            } else {
                snprintf(path, sizeof(path),
                    "/sys/class/hwmon/hwmon%d/temp%d_input", hwmon, sensor);
                if (!fopen(path, "r")) continue;
                snprintf(label, sizeof(label), "hwmon%d/temp%d", hwmon, sensor);
            }

            snprintf(path, sizeof(path),
                "/sys/class/hwmon/hwmon%d/temp%d_input", hwmon, sensor);
            fp = fopen(path, "r");
            if (!fp) continue;

            fscanf(fp, "%d", &temp);
            fclose(fp);

            printf("%-20s %d.%d °C\n", label, temp / 1000, (temp % 1000) / 100);
        }
    }
}

int main(void) {
    while (1) {
        read_temps();
        sleep(1);   // refresh every second
    }
    return 0;
}