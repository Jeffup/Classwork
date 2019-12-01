//

#include "pch.h"
#include "framework.h"
#include "MFCApplication3.h"
#include "MFCARPDlg.h"
#include "afxdialogex.h"
#include <tchar.h>
#include "ARP_HEAD.h"

#include<Windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
const int STR_BUFF_SIZE = 1000;

// CARPDlg 对话框
CARPDlg::CARPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//--------------
	alldevs = nullptr; //所有网络适配器
//	d = nullptr;
	flag = 0;
	errbuf = new char[PCAP_ERRBUF_SIZE];
//	adhandle = nullptr; //捕捉实例,是pcap_open返回的对象
//	ip_addr = new char(sizeof(char) * 16); //IP地址
//	ip_netmask = new char(sizeof(char) * 16); //子网掩码
//	ip_mac = new unsigned char(sizeof(char) * 6); //本机MAC地址
}

void CARPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//void AFXAPI DDX_Control(CDataExchange* pDX, int nIDC, CWnd& rControl);
	DDX_Control(pDX, IDC_ADAPTER_WIN, ADAPTER_WIN);
	DDX_Control(pDX, IDC_TIPS_WIN, TIPS_WIN);
	DDX_Control(pDX, IDC_IPMAC_WIN, IPMAC_WIN);
	DDX_Control(pDX, IDC_ADAPTER_CHOOSE, ADAPTER_CHOOSE);
	DDX_Control(pDX, IDC_SCAN_NETWORK, SCAN_NETWORK);	
	DDX_Control(pDX, IDC_QUIT, QUIT);
}

BEGIN_MESSAGE_MAP(CARPDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SCAN_ADAPTER, &CARPDlg::OnBnClickedScanAdapter)
	ON_BN_CLICKED(IDC_SCAN_NETWORK, &CARPDlg::OnBnClickedScanNetwork)
	ON_BN_CLICKED(IDC_QUIT, &CARPDlg::OnBnClickedQuit)
END_MESSAGE_MAP()


// CARPDlg 消息处理程序

BOOL CARPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CARPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CARPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CARPDlg::SearchAdapter()
{
	if (pcap_findalldevs_ex((char*)PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1)
	{ //结果为-1代表出现获取适配器列表失败 
		TIPS_WIN.InsertString(-1, "*********");
		TIPS_WIN.InsertString(-1, "获取适配器列表失败。");
		TIPS_WIN.InsertString(-1, "*********");
		//exit(0)代表正常退出,exit(other)为非正常退出,这个值会传给操作系统 
		exit(1);
	}
}
void CARPDlg::OnBnClickedScanAdapter()
{
	// TODO: 在此添加控件通知处理程序代码
	TIPS_WIN.InsertString(-1, "*********");
	TIPS_WIN.InsertString(-1, "点击了扫描适配器按钮！开始扫描！");
	//---适配器
	//---清理消息！
	ADAPTER_WIN.ResetContent();
	//---
	SearchAdapter();
	//---
	pcap_if_t* d;
	for (d = alldevs; d != NULL; d = d->next)
	{
		i++;
		char* str = new char[STR_BUFF_SIZE];

		int j;
		j = sprintf_s(str, STR_BUFF_SIZE, "%d : 设备名称：\n\t%s\n", i, d->name);
		ADAPTER_WIN.InsertString(-1, (LPCTSTR)str);
		if (d->description)
		{
			j = sprintf_s(str, STR_BUFF_SIZE, "   设备描述：\n\t%s\n", d->description);
			ADAPTER_WIN.InsertString(-1, (LPCTSTR)str);
		}
		else {
			//适配器不存在描述信息
			ADAPTER_WIN.InsertString(-1, (LPCTSTR) "不存在描述信息");
		}
		delete[]str;
	}
	//i为0代表上述循环未进入,即没有找到适配器,可能的原因为Winpcap没有安装导致未扫描到 
	if (i == 0)
	{
		//MessageBoxA(
		//	_In_opt_ HWND hWnd,
		//	_In_opt_ LPCSTR lpText,
		//	_In_opt_ LPCSTR lpCaption,
		//	_In_ UINT uType);
		TIPS_WIN.InsertString(-1, "*********");
		TIPS_WIN.InsertString(-1, "我没找到网卡啊！可能的原因为Winpcap没有安装导致未扫描到？还是你根本没有？");
		TIPS_WIN.InsertString(-1, "*********");
	}
	else
	{
		char* str = new char[STR_BUFF_SIZE];
		int j;
		ADAPTER_CHOOSE.ResetContent();
		for (int k = 1; k <= i; k++)
		{
			j = sprintf_s(str, STR_BUFF_SIZE, "%d", k);
			ADAPTER_CHOOSE.AddString((LPCTSTR)str);
		}
		delete[]str;
		ADAPTER_CHOOSE.SetCurSel(0);

		TIPS_WIN.InsertString(-1, "*********");
		TIPS_WIN.InsertString(-1, "扫描成功,选择一个适配器进行抓包。");
		TIPS_WIN.InsertString(-1, "*********");
		//int index = ((CComboBox*)GetDlgItem(IDC_ADAPTER_CHOOSE))->GetCurSel();
	}
}
#define IPTOSBUFFERS    12 
char* CARPDlg::iptos(u_long in)
{
	static char output[IPTOSBUFFERS][3 * 4 + 3 + 1];
	static short which; u_char* p; p = (u_char*)& in;
	which = (which + 1 == IPTOSBUFFERS ? 0 : which + 1);
	sprintf_s(output[which], "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
	return output[which];
}
//获取IP和子网掩码赋值为ip_addr和ip_netmask 
void CARPDlg::ifget(pcap_if_t* d)
{
	char* str = new char[STR_BUFF_SIZE];
	sprintf_s(str, STR_BUFF_SIZE, "你选择的适配器名:%s\n正在获取网卡IP&MAC中……", d->name);

	TIPS_WIN.InsertString(-1, str);
	delete[]str;

	pAddr = d->addresses;

	//得到用户选择的网卡的一个IP地址 
	this->ip_addr = ((struct sockaddr_in*)pAddr->addr)->sin_addr.s_addr;
	//得到该IP地址对应的子网掩码 
	this->ip_netmask = ((struct sockaddr_in*)(pAddr->netmask))->sin_addr.S_un.S_addr;
	if (d->addresses != NULL)
		this->ip_netmask = ((struct sockaddr_in*)(d->addresses->netmask))->sin_addr.S_un.S_addr;
	else
		// 如果接口没有地址，那么我们假设一个C类的掩码
		this->ip_netmask = 0xffffff;
	
	str = new char[STR_BUFF_SIZE];
	sprintf_s(str, STR_BUFF_SIZE, "适配器IP地址：%s", iptos(ip_addr));
	TIPS_WIN.InsertString(-1, str);
	delete[]str;
	str = new char[STR_BUFF_SIZE];
	sprintf_s(str, STR_BUFF_SIZE, "子 网  掩 码：%s", iptos(ip_netmask));
	TIPS_WIN.InsertString(-1, str);
	delete[]str;
	TIPS_WIN.InsertString(-1, "*********");
}

UINT WINAPI GetLivePC_T(LPVOID param)
{
	CARPDlg* obj = (CARPDlg*)param;
	obj->GetLivePC();
	return 0;
}

void CARPDlg::OnBnClickedScanNetwork()
{
	pcap_if_t * d;
	int index = ((CComboBox*)GetDlgItem(IDC_ADAPTER_CHOOSE))->GetCurSel();
	for (d = alldevs, i = 0; i <= index - 1; d = d->next, i++);
	pdevname = d->name;
	ifget(d);
	
	pcap_t* adhandle;
	if ((adhandle = pcap_open(d->name, //设备名称 
		65535, //存放数据包的内容长度 
		PCAP_OPENFLAG_PROMISCUOUS, //混杂模式 
		1000, //超时时间
		NULL, //远程验证
		errbuf //错误缓冲 
	)) == NULL)
	{ //打开适配器失败,打印错误并释放适配器列表 
		char* str = new char[STR_BUFF_SIZE];
		sprintf_s(str, STR_BUFF_SIZE, "Unable to open the adapter.\n %s is not supported by WinPcap", d->name);
		TIPS_WIN.InsertString(-1, str);
		delete[]str;
	}
	//pcap_freealldevs(alldevs);
		//编译过滤器
	char packet_filter[] = "ether proto \\arp"; //设置正则表达式，只过滤arp包
	struct bpf_program fcode;
	if (pcap_compile(adhandle, &fcode, packet_filter, 1, ip_netmask) < 0)
	{
		// 释放设备列表 
		TIPS_WIN.AddString("编译过滤器失败！");
		TIPS_WIN.InsertString(-1, "*********");
		pcap_freealldevs(alldevs);
		return;
	}
	//设置过滤器
	if (pcap_setfilter(adhandle, &fcode) < 0)
	{
		TIPS_WIN.AddString("设置过滤器失败！");
		TIPS_WIN.InsertString(-1, "*********");
		// 释放设备列表 
		pcap_freealldevs(alldevs);
		return;
	}
	TIPS_WIN.AddString("正在监听局域网内的ARP包，请耐心等候...");
	TIPS_WIN.InsertString(-1, "*********");
	DWORD dwThreadId_t; 
	recvthread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)GetLivePC_T, (LPVOID)this, 0, &dwThreadId_t);
}
/* 向局域网内所有可能的IP地址发送ARP请求包线程 */
/* 分析截留的数据包获取活动的主机IP地址 */
int CARPDlg::GetLivePC() //(pcap_t *adhandle)
{
	int res;
	struct pcap_pkthdr* pkt_header;
	const u_char* pkt_data = new u_char[STR_BUFF_SIZE];
	pcap_t* adhandle;
	if ((adhandle = pcap_open(pdevname, //设备名称 
		65535, //存放数据包的内容长度 
		PCAP_OPENFLAG_PROMISCUOUS, //混杂模式 
		1000, //超时时间
		NULL, //远程验证
		errbuf //错误缓冲 
	)) == NULL)
	{ //打开适配器失败,打印错误并释放适配器列表 
		char* str = new char[STR_BUFF_SIZE];
		sprintf_s(str, STR_BUFF_SIZE, "Unable to open the adapter.\n %s is not supported by WinPcap", pdevname);
		TIPS_WIN.InsertString(-1, str);
		delete[]str;
	}
	Arpheader* arpheader;
	vector<u_long> IP_BUFFTER;
	int mysign = 0;
		while((res = pcap_next_ex(adhandle, &pkt_header, &pkt_data)) >= 0)
		{
			// 超时
			if (res == 0)continue;
			//获得ARP数据包 
			arpheader = (Arpheader*)(pkt_data);  //以太帧头部长度为14字节

						   // 打印活动主机IP地址
			char* str1 = new char[STR_BUFF_SIZE];
			
			//打印mac地址
			int k = 0;
			int j = 0;
			for (; j < 5; j++) {
				if (arpheader->SourceMacAdd[j] < 16)
					k += sprintf_s(str1 + k, STR_BUFF_SIZE - k, "0");
				k += sprintf_s(str1 + k, STR_BUFF_SIZE - k, "%x-", arpheader->SourceMacAdd[j]);
			}
			if (arpheader->SourceMacAdd[j] < 16)
				k += sprintf_s(str1 + k, STR_BUFF_SIZE - k, "0");
			k += sprintf_s(str1 + k, STR_BUFF_SIZE - k, "%x", arpheader->SourceMacAdd[j]);

			if (arpheader->DestIpAdd == this->ip_addr && mysign == 0)
			{
				this->ip_mac = arpheader->SourceMacAdd;
				char* str = new char[STR_BUFF_SIZE];
				sprintf_s(str, STR_BUFF_SIZE, "本机MAC地址 ：%s", str1);
				delete[]str;
				TIPS_WIN.InsertString(-1, "*********");
				mysign = 1;
			}

				int m = 0;
				for (; m < IP_BUFFTER.size(); m++)
				{
					if (IP_BUFFTER.at(m) == arpheader->SourceIpAdd)
						break;
				}
				if (m >= IP_BUFFTER.size())
				{
					char* str2 = new char[STR_BUFF_SIZE];
					IPMAC_WIN.InsertString(-1, "-------------");
					sprintf_s(str2, STR_BUFF_SIZE, "IP地址:%s", iptos(arpheader->SourceIpAdd));
					IPMAC_WIN.InsertString(-1, str2);
					delete[]str2;
					str2 = new char[STR_BUFF_SIZE];
					sprintf_s(str2, STR_BUFF_SIZE, "MAC地址:%s", str1);
					IPMAC_WIN.InsertString(-1, str2);
					delete[]str1;
					IP_BUFFTER.push_back(arpheader->SourceIpAdd);
				}
			
			

		} Sleep(10);
	pcap_close(adhandle);
	TIPS_WIN.AddString("扫描完毕！");
	TIPS_WIN.InsertString(-1, "*********");
	return 0;
}

void CARPDlg::OnBnClickedQuit()
{
	char* str = new char[STR_BUFF_SIZE];

	if (!recvthread)
	{
		sprintf_s(str, STR_BUFF_SIZE, "找不到进程！");

		TIPS_WIN.InsertString(-1, str);
		TIPS_WIN.InsertString(-1, "*********");
		return;
	}
	if (CloseHandle(recvthread))
	{
		sprintf_s(str, STR_BUFF_SIZE, "取消扫描！");
		
		TIPS_WIN.InsertString(-1, str);
		TIPS_WIN.InsertString(-1, "*********");
	}
	else
	{
		sprintf_s(str, STR_BUFF_SIZE, "取消失败：%d",GetLastError());
		
		TIPS_WIN.InsertString(-1, str);
		TIPS_WIN.InsertString(-1, "*********");
	}
	delete[]str;
	// TODO: 在此添加控件通知处理程序代码
}
