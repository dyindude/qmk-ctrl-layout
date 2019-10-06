FROM local/qmk_firmware

RUN make massdrop/ctrl:all && \
    cp *.bin /
