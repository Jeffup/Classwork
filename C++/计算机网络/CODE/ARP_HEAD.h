#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "pcap.h"
//֡ͷ���ṹ�壬��14�ֽ� 

#define ETH_ARP         0x0806  //��̫��֡���ͱ�ʾ�������ݵ����ͣ�����ARP�����Ӧ����˵�����ֶε�ֵΪx0806
#define ARP_HARDWARE    1  //Ӳ�������ֶ�ֵΪ��ʾ��̫����ַ 
#define ETH_IP          0x0800  //Э�������ֶα�ʾҪӳ���Э���ַ����ֵΪx0800��ʾIP��ַ 
#define ARP_REQUEST     1   //ARP���� 
#define ARP_REPLY       2      //ARPӦ�� 
#define HOSTNUM         255   //��������

////֡ͷ���ṹ�壬��14�ֽ� 
struct EthernetHeader
{ 
	u_char DestMAC[6]; //Ŀ��MAC��ַ 6�ֽ�
	u_char SourMAC[6]; //ԴMAC��ַ 6�ֽ�
	u_short EthType; //��һ��Э�����ͣ���0x0800������һ����IPЭ�飬0x0806Ϊarp  2�ֽ� 
}; 
////28�ֽ�ARP֡�ṹ 
struct Arpheader 
{ 
	u_char DestMAC[6]; //Ŀ��MAC��ַ 6�ֽ�
	u_char SourMAC[6]; //ԴMAC��ַ 6�ֽ�
	u_short EthType; //��һ��Э�����ͣ���0x0800������һ����IPЭ�飬0x0806Ϊarp  2�ֽ� 
	unsigned short HardwareType; //Ӳ������ 
	unsigned short ProtocolType; //Э������ 
	unsigned char HardwareAddLen; //Ӳ����ַ���� 
	unsigned char ProtocolAddLen; //Э���ַ���� 
	unsigned short OperationField; //�����ֶ� 
	unsigned char SourceMacAdd[6]; //Դmac��ַ 
	unsigned long SourceIpAdd; //Դip��ַ 
	unsigned char DestMacAdd[6]; //Ŀ��mac��ַ 
	unsigned long DestIpAdd; //Ŀ��ip��ַ 
}; 
//arp���ṹ 
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

