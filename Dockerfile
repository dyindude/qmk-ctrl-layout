FROM local/qmk_firmware

COPY keymaps /qmk_firmware/keyboards/massdrop/ctrl/keymaps

RUN make massdrop/ctrl:testlayout
RUN cp massdrop_ctrl_testlayout.bin /
