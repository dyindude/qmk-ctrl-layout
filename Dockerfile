FROM local/qmk_firmware

RUN rm -rf /qmk_firmware/keyboards/massdrop/ctrl/keymaps/*

COPY keymaps /qmk_firmware/keyboards/massdrop/ctrl/keymaps2

RUN rm -rf /qmk_firmware/keyboards/massdrop/ctrl/keymaps && \
    mv  /qmk_firmware/keyboards/massdrop/ctrl/keymaps2 /qmk_firmware/keyboards/massdrop/ctrl/keymaps && \
    make massdrop/ctrl:all && \
    cp *.bin /
