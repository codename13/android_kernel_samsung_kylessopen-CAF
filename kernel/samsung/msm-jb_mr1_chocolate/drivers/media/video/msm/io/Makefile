GCC_VERSION      := $(shell $(CONFIG_SHELL) $(PWD)/scripts/gcc-version.sh $(CROSS_COMPILE)gcc)
  obj-$(CONFIG_MSM_CAMERA) += msm_camera_i2c.o msm_camera_eeprom.o
ifneq ($(CONFIG_MSM_CAMERA_LEGACY),y)
  obj-$(CONFIG_MSM_CAMERA)   += msm_camera_io_util.o
endif
ifeq ($(CONFIG_MSM_CAMERA_LEGACY),y)
  obj-$(CONFIG_ARCH_MSM7X27A) += msm_io_7x27a_legacy.o
else
   obj-$(CONFIG_ARCH_MSM7X27A) += msm_io_7x27a.o
endif
