package main

import(
	"net/http"
	"net"
	"os"
	"log"
)
func GeLocalIP() string {
	addrs, err := net.InterfaceAddrs()
	if err != nil {
	   return ""
	}
	for _, addr := range addrs {
	   if ip, ok := addr.(*net.IPNet); ok && !ip.IP.IsLoopback() {
		  if ip.IP.To4() != nil {
			 return ip.IP.String()
		  }
	   }
	}
	return ""
 }
func main() {
	ip:=GeLocalIP()
	if ip==""{
		log.Fatalln("ip error! Internet?")
		os.Exit(0)
	}
	log.Println("file server is running at",ip+":7850")
    fs := http.FileServer(http.Dir("."))
    http.Handle("/file/", http.StripPrefix("/file/", fs))
    http.ListenAndServe(":7850", nil)

}
