package main

type Keymap struct {
	Keyboard string     `json:"keyboard"`
	Name     string     `json:"keymap"`
	Layout   string     `json:"layout"`
	Layers   [][]string `json:"layers"`
}
