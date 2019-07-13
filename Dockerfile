FROM local/qmk_firmware

VOLUME /qmk_firmware

RUN rm -rf /qmk_firmware/keyboards/massdrop/ctrl/keymaps/*

COPY keymaps /qmk_firmware/keyboards/massdrop/ctrl/keymaps

RUN pwd && make massdrop/ctrl:testlayout && cp *.bin /
