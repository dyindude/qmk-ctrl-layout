FROM local/qmk_firmware

RUN make massdrop/ctrl:testlayout && \
    cp *.bin /
