package main

//need to account for ANY( keyword)
import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"regexp"
	"strings"
	"text/template"
)

func main() {
	var labels = map[int]string{
		0: "_BASE",
		1: "_META",
		2: "_FUNC",
	}
	jsonFile, err := os.Open("keymap.json")
	// if we os.Open returns an error then handle it
	if err != nil {
		fmt.Println(err)
	}
	// defer the closing of our jsonFile so that we can parse it later on
	defer jsonFile.Close()
	var keymap Keymap
	byteValue, _ := ioutil.ReadAll(jsonFile)

	json.Unmarshal(byteValue, &keymap)
	tmpl, err := template.New("keymap.tmpl").
		Funcs(template.FuncMap{"StringsJoin": func(s []string) string {
			o := strings.Join(s, ", ")
			re := regexp.MustCompile(`ANY\((.*?)\)`)
			o = re.ReplaceAllString(o, `$1`)
			return o
		}}).
		Funcs(template.FuncMap{"label": func(n int) string { return labels[n] }}).
		ParseFiles("keymap.tmpl")
	if err != nil {
		fmt.Println(err)
	}
	//tmpl.Funcs(template.FuncMap{"StringsJoin": strings.Join})
	err = tmpl.Execute(os.Stdout, keymap)
	if err != nil {
		fmt.Println(err)
	}
}
