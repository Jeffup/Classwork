#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "pcap.h"
//帧头部结构体，共14字节 

#define ETH_ARP         0x0806  //以太网帧类型表示后面数据的类型，对于ARP请求或应答来说，该字段的值为x0806
#define ARP_HARDWARE    1  //硬件类型字段值为表示以太网地址 
#define ETH_IP          0x0800  //协议类型字段表示要映射的协议地址类型值为x0800表示IP地址 
#define ARP_REQUEST     1   //ARP请求 
#define ARP_REPLY       2      //ARP应答 
#define HOSTNUM         255   //主机数量

////帧头部结构体，共14字节 
struct EthernetHeader
{ 
	u_char DestMAC[6]; //目的MAC地址 6字节
	u_char SourMAC[6]; //源MAC地址 6字节
	u_short EthType; //上一层协议类型，如0x0800代表上一层是IP协议，0x0806为arp  2字节 
}; 
////28字节ARP帧结构 
struct Arpheader 
{ 
	u_char DestMAC[6]; //目的MAC地址 6字节
	u_char SourMAC[6]; //源MAC地址 6字节
	u_short EthType; //上一层协议类型，如0x0800代表上一层是IP协议，0x0806为arp  2字节 
	unsigned short HardwareType; //硬件类型 
	unsigned short ProtocolType; //协议类型 
	unsigned char HardwareAddLen; //硬件地址长度 
	unsigned char ProtocolAddLen; //协议地址长度 
	unsigned short OperationField; //操作字段 
	unsigned char SourceMacAdd[6]; //源mac地址 
	unsigned long SourceIpAdd; //源ip地址 
	unsigned char DestMacAdd[6]; //目的mac地址 
	unsigned long DestIpAdd; //目的ip地址 
}; 
//arp包结构 
struct ArpPacket 
{ 
	EthernetHeader ed;
	Arpheader ah;
}; 
//struct sparam
//{ 
//	pcap_t *adhandle; 
//	char *ip;
//	unsigned char *mac; 
//	char *netmask;
//}; 
//struct gparam 
//{ 
//	pcap_t *adhandle; 
//};
//struct sparam sp; 
//struct gparam gp;

