FROM local/qmk_firmware

COPY keymaps /qmk_firmware/keyboards/massdrop/ctrl/keymaps

RUN pwd && make massdrop/ctrl:testlayout && cp *.bin /
