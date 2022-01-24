set(srcs)

idf_component_register(SRCS "mypwm.c" "${srcs}"
                    INCLUDE_DIRS  "."
                    REQUIRES console nvs_flash bt
                    REQUIRED_IDF_TARGETS esp32)
