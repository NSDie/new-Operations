
// Operations3.2.1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Operations3.2.1.h"
#include "Operations3.2.1Dlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COperations321Dlg 对话框



COperations321Dlg::COperations321Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OPERATIONS321_DIALOG, pParent)
	, v()
	, txt(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COperations321Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, txt);
	DDX_Text(pDX, IDC_EDIT3, v);
	DDX_Text(pDX, IDC_EDIT1, txt);
}

BEGIN_MESSAGE_MAP(COperations321Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &COperations321Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &COperations321Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &COperations321Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COperations321Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &COperations321Dlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT3, &COperations321Dlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// COperations321Dlg 消息处理程序

BOOL COperations321Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemText(IDC_EDIT3, NULL);
	// 将“关于...”菜单项添加到系统菜单中。
	
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void COperations321Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COperations321Dlg::OnPaint()
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
HCURSOR COperations321Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COperations321Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	
	
	// TODO:  在此添加控件通知处理程序代码
}

int flag = 0;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;

void COperations321Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == 0)
	{
		txt = "欢迎使用自动出题软件           ver 3.2.1  \r\nps:还在测试阶段，目前只有一种语言可以使用 \r\n  \r\n使用说明 ：\r\n 1.点击出题即可出现随机生成算式 \r\n 2.在下方答案框中输入答案  \r\n 3.点击提交查看正误  \r\n 4.退出时可以查看题数 \r\n   欢迎您的使用以及提出宝贵的意见！";
		flag = 1;
	}
	
	UpdateData(false);
	
}
int randNum()
{
	
	return 1 + rand() % 9;
}
int randSym()
{
	
	return 1 + rand() % 3;
}
char symbol(int i)
{
	switch (i)
	{
	case 1:  return '+';
		break;
	case 2:  return '-';
		break;
	case 3:  return '*';
		break;
	}
}

char *str = new char[10];
double amount = 0;
double r = 0;
void COperations321Dlg::OnBnClickedButton1()
{
	if (flag == 1&&flag3 == 0)
	{
		srand((unsigned)time(NULL));
		UpdateData(TRUE);
		if (flag2 == 0)
		{
			GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
			flag2 = 1;
		}


		//string str;
		int i, num[5], sign[5], k;
		char sym[5];
		k = 1;
		for (i = 1; i <= 4; i++)
			num[i] = randNum();
		for (i = 1; i <= 3; i++)
			sign[i] = randSym();
		for (i = 1; i <= 3; i++)
			sym[i] = symbol(sign[i]);
		int temp;
		for (i = 1; i <= 4; i++)
			str[(i - 1) * 2] = '0' + num[i];
		for (i = 1; i <= 3; i++)
			str[i * 2 - 1] = sym[i];
		temp = rand() % 2;
		for (i = 7; i > temp * 2; i--)
			str[i] = str[i - 1];
		str[temp * 2] = '(';
		str[8] = ')';
		str[9] = '=';
		str[10] = '\0';
		CString cstr = str;

		if (flag1 == 0)
		{
			txt = cstr;
			txt += "\r\n";
			flag1 = 1;
		}
		else
		{
			txt += cstr;
			txt += "\r\n";
		}
		flag3 = 1;
		amount++;
		
		UpdateData(false);
	}
	// TODO: 在此添加控件通知处理程序代码
}

int check(char str[])//用于计算生成的运算式的结果

{
	int  sum, i, t, top = 0;
	double d;
	char exp[15];
	char stack[15];
	char ch;
	sum = 8;
	t = 1; i = 0;
	str[9] = '#';
	ch = str[i]; i++;
	while (ch != '#')
	{
		switch (ch)
		{
		case '(':  /*判定为左括号*/
			top++; stack[top] = ch;
			break;
		case ')':  /*判定为右括号*/
			while (stack[top] != '(')
			{
				exp[t] = stack[top]; top--; t++;
			}
			top--;
			break;
		case '+':   /*判定为加减号*/
		case '-':
			while (top != 0 && stack[top] != '(')
			{
				exp[t] = stack[top]; top--; t++;
			}
			top++; stack[top] = ch;
			break;
		case '*':  /*判定为'*'或'/'号*/
		case '/':
			while (stack[top] == '*' || stack[top] == '/')
			{
				exp[t] = stack[top]; top--; t++;
			}
			top++; stack[top] = ch;
			break;
		case ' ':break;
		default:
			while (ch >= '0' && ch <= '9') /*判定为数字*/
			{
				exp[t] = ch; t++;
				ch = str[i]; i++;
			}
			i--;
			exp[t] = '#'; t++;
		}
		ch = str[i]; i++;
	}
	while (top != 0)
	{
		exp[t] = stack[top]; t++; top--;
	}
	exp[t] = '#';
	t = 1; top = 0;
	ch = exp[t]; t++;
	while (ch != '#')
	{
		switch (ch)
		{
		case '+':stack[top - 1] = stack[top - 1] + stack[top];
			top--; break;
		case '-':stack[top - 1] = stack[top - 1] - stack[top];
			top--; break;
		case '*':stack[top - 1] = stack[top - 1] * stack[top];
			top--; break;
		case '/':if (stack[top] != 0)
			stack[top - 1] = stack[top - 1] / stack[top];
				 else
				 {
					 printf("\n\t除零错误!\n");
					 exit(0);/*异常退出*/
				 }
				 top--; break;
		default:d = 0;
			while (ch >= '0' && ch <= '9')   /*判定为数字字符*/
			{
				d = 10 * d + ch - '0';  /*将数字字符转换成对应的数值*/
				ch = exp[t]; t++;
			}
			top++;
			stack[top] = char(d);
		}
		ch = exp[t]; t++;
	}
	return stack[top];
}
void COperations321Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == 1&&flag3==1)
	{
		UpdateData(TRUE);
		CString a;
		if (v == check(str))
		{
			txt += "恭喜你！ 答对啦！ \(^o^)/";
			txt += "\r\n";
			r++;
			UpdateData(false);
		}
		else
		{
			a.Format("%d", check(str));
			txt += "可惜答错了！ 正确答案是：";
			txt += a;
			txt += "\r\n";
			UpdateData(false);
		}
		flag3 = 0;
	}
}


void COperations321Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == 1&&amount>0)
	{
		CString cc;
		CString rr, aa, ff;
		double f;
		f = r / amount;
		f *= 100.00;
		ff.Format(_T("%.2lf"), f);
		rr.Format("%.0lf", r);
		aa.Format("%.0lf", amount);
		cc += "总共回答了";
		cc += aa;
		cc += "道题目，";
		cc += "答对了";
		cc += rr;
		cc += "道题目，";
		cc += "准确率为：";
		cc += ff;
		cc += "%.";
		MessageBox(cc, "题数总结", MB_OK);
	}
	CDialogEx::OnCancel();
}


void COperations321Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	
	// TODO:  在此添加控件通知处理程序代码
}
