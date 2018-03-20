#include <stdio.h>
#include "hidapi.h"
#include <windows.h>
#define BATTERY_MAX 91
#define BATTERY_MIN 44

int main(int argc, char* argv[])
{
	unsigned int batteryPercent = -1;
	bool foundFlag = false;
	int res;
	hid_device *handle;
	int i;
	unsigned char buf[64] = { 0xFF, 0x09, 0, 0xFD, 0xF4, 0x10, 0x05, 0xB1, 0xBF, 0xA0, 0x04, 0x00, 0, 0, 0, 0 };
	for (i = 16; i < 64; i++)
		buf[i] = 0;

	if (hid_init())
		return -1;

	struct hid_device_info *devs, *cur_dev;
	devs = hid_enumerate(0x0, 0x0);
	cur_dev = devs;

	while (cur_dev && !foundFlag) {
		if (cur_dev->vendor_id == 0x046d && cur_dev->product_id == 0x0a1f) {
			handle = hid_open_path(cur_dev->path);
			
			if (handle) {
				foundFlag = true;
				res = hid_send_feature_report(handle, buf, 64);
				if (res < 0) {
					printf("Failed to send feature report: %ls\n", hid_error(handle));
					return 1;
				}
	
				for (i = 0; i < 3; i++) {
					res = hid_get_feature_report(handle, buf, 64);
	
					if (res < 0) {
						printf("Failed to get feature report %d: %ls\n", i, hid_error(handle));
						return 1;
					}

					if (i < 2) {
						Sleep(100);
					}
				}
				batteryPercent = (buf[13] - BATTERY_MIN) * 100 / (BATTERY_MAX - BATTERY_MIN);
				printf("%d\n", batteryPercent);
				hid_close(handle);
				hid_exit();
			}
		}
		cur_dev = cur_dev->next;
	}
	return 0;
}
