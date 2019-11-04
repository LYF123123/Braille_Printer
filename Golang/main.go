package main

import (
	"fmt"
	"github.com/tarm/serial"
	"log"
	"time"
)

func main() {

	// Set Serial Port and Baud
	c := &serial.Config{Name: "COM7", Baud: 115200}

	// Open Serial Port
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}
	//str := []byte("printerVersion")

	ping := []byte("printerVersion")
	var prPointOne byte = 0x82
	var prPointTwo byte = 0x83
	var prPointThree byte = 0x84
	var prPointFour byte = 0x85
	var prPointFive byte = 0x86
	var prPointSix byte = 0x87
	var prPointSeven byte = 0x88
	var prSpacePoint byte = 0x89
	var prSpaceWord byte = 0x8A
	var prChangeLine byte = 0x8B
	var prMarginTop byte=0x91
	var prMarginBottom byte=0x92
	var prMarginLeft byte=0x93
	//var prMarginRight byte =0x94
	var adPoint byte = 0xA1
	var adWord byte = 0xA2
	var adLine byte = 0xA3
	var adMarginTop byte =0xA4
	var adMarginBottom byte =0xA5
	var adMarginLeft byte=0xA6
	var adMarginRight byte = 0xA7
	var prtInitialize byte = 0xB1
	//var prtCuInitialize byte =0xB2
	var prtFeedPaper byte = 0xB3
	//var prtPause byte = 0xB4
	//var prtResume byte =0xB5
	//var prtStop byte = 0xB6
	initialization := []byte{1, 2, adPoint, 3, 9, adWord, 5, 5, adLine,6,6,adMarginTop,6,6,adMarginBottom,3,3,adMarginLeft,3,3,adMarginRight,prtInitialize,
		prtFeedPaper,}
	normalWord := []byte{prMarginTop,prMarginLeft,prPointOne, prSpacePoint, prPointTwo, prSpaceWord, prPointThree, prSpacePoint, prPointFour, prSpaceWord,
		prPointFive, prSpacePoint, prPointSix, prSpaceWord, prPointSeven, prSpacePoint,prPointSeven, prChangeLine,prSpacePoint, prPointTwo, prSpaceWord, prPointThree, prSpacePoint, prPointFour, prSpaceWord,
		prPointFive, prSpacePoint, prPointSix, prSpaceWord, prPointSeven, prSpacePoint,prPointSeven,prMarginBottom}

	// Write a String
	n, err := s.Write(ping)
	n, err = s.Write(ping)
	n, err = s.Write(initialization)
	n, err = s.Write(ping)
	n, err = s.Write(ping)
	n, err = s.Write(normalWord)
	n, err = s.Write(normalWord)
	n, err = s.Write(normalWord)
	n, err = s.Write(normalWord)
	n, err = s.Write(normalWord)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Write %d Bytes\r\n", n)
	time.Sleep(1 * time.Second)
	// make and set a buff
	buf := make([]byte, 65535)

	n, err = s.Read(buf)
	if err != nil {
		log.Fatal(err)
	}
	//log.Print("%q", buf[:n])
	fmt.Printf("Read %d Bytes\r\n", n)
	for i := 0; i < n; i++ {
		//fmt.Printf("buf[%d]=%c ", i, buf[i])
		fmt.Printf("%c", buf[i])
	}
	n = 0
}
