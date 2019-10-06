FROM local/qmk_firmware

RUN make massdrop/ctrl:dyindude_md && \
    cp *.bin /
