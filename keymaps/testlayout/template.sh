length=$(($(cat keymap.json | jq -cM ".layers | length")-1))
echo '//layouts..using QMK configurator to generate these for now
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {'
for i in $(seq 0 $length);do
    echo -n "[$i] = LAYOUT("
    cat keymap.json | jq -cM ".layers[$i]" | sed 's/\"//g;s/\[//g;s/\]/),/g'
done
echo '};'
