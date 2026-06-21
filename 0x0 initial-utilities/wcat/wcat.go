package main

import (
	"fmt"
	"os"
)

func main(){
	files := os.Args[1:]
	
	for _, file := range files {
		data, err := os.ReadFile(file)
	
		if err != nil{
			fmt.Printf("%e", err)
		}

		fmt.Printf("%v", string(data))
	}

}
