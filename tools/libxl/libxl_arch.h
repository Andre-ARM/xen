/*
 * Copyright (C) 2012      Citrix Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; version 2.1 only. with the special
 * exception on linking described in file LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 */

#ifndef LIBXL_ARCH_H
#define LIBXL_ARCH_H

/* fill the arch specific configuration for the domain */
_hidden
int libxl__arch_domain_prepare_config(libxl__gc *gc,
                                      libxl_domain_config *d_config,
                                      xc_domain_configuration_t *xc_config);

/* save the arch specific configuration for the domain */
_hidden
int libxl__arch_domain_save_config(libxl__gc *gc,
                                   libxl_domain_config *d_config,
                                   const xc_domain_configuration_t *xc_config);

/* arch specific internal domain creation function */
_hidden
int libxl__arch_domain_create(libxl__gc *gc, libxl_domain_config *d_config,
               uint32_t domid);

/* setup arch specific hardware description, i.e. DTB on ARM */
_hidden
int libxl__arch_domain_init_hw_description(libxl__gc *gc,
                                           libxl_domain_build_info *info,
                                           libxl__domain_build_state *state,
                                           struct xc_dom_image *dom);
/* finalize arch specific hardware description. */
_hidden
int libxl__arch_domain_finalise_hw_description(libxl__gc *gc,
                                      libxl_domain_build_info *info,
                                      struct xc_dom_image *dom);

/* build vNUMA vmemrange with arch specific information */
_hidden
int libxl__arch_vnuma_build_vmemrange(libxl__gc *gc,
                                      uint32_t domid,
                                      libxl_domain_build_info *b_info,
                                      libxl__domain_build_state *state);

/* arch specific irq map function */
_hidden
int libxl__arch_domain_map_irq(libxl__gc *gc, uint32_t domid, int irq);

#endif
