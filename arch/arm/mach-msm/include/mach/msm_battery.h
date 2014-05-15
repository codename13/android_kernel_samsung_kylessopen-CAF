/* Copyright (c) 2009, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */


#ifndef __MSM_BATTERY_H__
#define __MSM_BATTERY_H__

#define NO_CHG     0x00000000
#define AC_CHG     0x00000001
#define USB_CHG    0x00000002
#ifdef CONFIG_CHARGER_SMB328A
#include <linux/smb328a_charger.h>
#endif

enum cable_type_t {
	CABLE_TYPE_UNKNOWN = 0,
	CABLE_TYPE_USB,
	CABLE_TYPE_TA,
    CABLE_TYPE_USB_OTG,
};

enum acc_type_t {
	ACC_TYPE_NONE = 0,
	ACC_TYPE_USB,
	ACC_TYPE_CHARGER,
	ACC_TYPE_CAR_DOCK,
	ACC_TYPE_DESK_DOCK,
	ACC_TYPE_JIG,
};

enum ovp_type_t {
	OVP_TYPE_NONE = 0,
	OVP_TYPE_OVP,
	OVP_TYPE_RECOVER,
};

extern bool power_down;
extern int charging_boot;
static int set_timer;

struct msm_battery_callback {
	void (*set_cable)(struct msm_battery_callback *ptr,
		enum cable_type_t status);
	void (*set_acc_type)(struct msm_battery_callback *ptr,
		enum acc_type_t status);
	void (*set_ovp_type)(struct msm_battery_callback *ptr,
		enum ovp_type_t status);
#ifdef CONFIG_CHARGER_SMB328A
	void (*charge_done)(struct msm_battery_callback *ptr);	/* switching charger */
#endif
};

struct msm_charger_data {
	struct power_supply *psy_fuelgauge;
#ifdef CONFIG_CHARGER_SMB328A
	struct smb328a_platform_data *charger_ic;	/* SMB328A switching charger */
#endif
	void (*register_callbacks)(struct msm_battery_callback *ptr);
};

struct msm_psy_batt_pdata {
	struct msm_charger_data	*charger;
	u32 voltage_max_design;
	u32 voltage_min_design;
	u32 avail_chg_sources;
	u32 batt_technology;
	u32 (*calculate_capacity)(u32 voltage);
};

#endif
