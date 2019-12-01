//

#pragma once
#include <pcap.h>
#include <conio.h> 
#include <packet32.h> 
#include <ntddndis.h> 
#include<string>
#include<vector>
using namespace std;

#define ETH_ARP         0x0806  //以太网帧类型表示后面数据的类型，对于ARP请求或应答来说，该字段的值为x0806
#define ARP_HARDWARE    1  //硬件类型字段值为表示以太网地址
#define ETH_IP          0x0800  //协议类型字段表示要映射的协议地址类型值为x0800表示IP地址
#define ARP_REQUEST     1   //ARP请求 
#define ARP_REPLY       2      //ARP应答 
#define HOSTNUM         255   //主机数量

// CARPDlg 对话框

static UINT WINAPI GetLivePC_T(LPVOID param);
static UINT WINAPI GetLivePC_T(LPVOID param);
class CARPDlg : public CDialogEx
{
	// 构造
public:
	CARPDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedScanAdapter();


protected:
	// 适配器数组
	pcap_if_t* alldevs; //所有网络适配器
		//pcap_t* adapter;
	// 选中的网络适配器
	pcap_addr_t* pAddr; //网卡地址 
	char* pdevname;
	bool flag;
	char* errbuf; //错误缓冲区,大小为256 
	//pcap_t* adhandle; //捕捉实例,是pcap_open返回的对象 
	int i = 0; //适配器计数变量
	u_long ip_addr; //IP地址
	u_long ip_netmask; //子网掩码
	unsigned char* ip_mac; //本机MAC地址

	HANDLE recvthread;       //接受ARP包线程

public:
	CListBox ADAPTER_WIN;

	CListBox TIPS_WIN;
	CListBox IPMAC_WIN;

	CComboBox ADAPTER_CHOOSE;
	CButton  SCAN_ADAPTER;
	CButton  SCAN_NETWORK;
	CButton QUIT;

	void SearchAdapter();
	char* iptos(u_long in);       //u_long即为 unsigned long
	void ifget(pcap_if_t* d);//获取IP和子网掩码赋值为ip_addr和ip_netmask
	int GetLivePC();
	afx_msg void OnBnClickedScanNetwork();
	afx_msg void OnBnClickedQuit();
};
//bool CARPDlg::flag = 0;