#pragma once

#include "resource.h"

//函数声明
void checkComplite();  //  查看一行是否能消去
void drawBlocked(HDC hdc);      //绘制当前已经存在砖块的区域
void DrawBackGround(HDC hdc);       //绘制背景
void outPutBoxInt(int num);     //自定义的弹窗函数  用于调试，已经被注释掉了
void outPutBoxString(TCHAR str[1024]);
void setRandomT();      //设置随机方块形状
void init_game();       //游戏初始化
void fillBlock();       //到达底部后填充矩阵
void RotateTeris(BOOL bTeris[4][4]);        //旋转方块
void DrawTeris(HDC mdc);    //绘制方块
void drawNext(HDC hdc); //绘制下一个将要掉落的方块
void drawScore(HDC hdc);    //显示得分
void drawCompleteParticle(int line);

int RandomInt(int _min, int _max);       //设置随即方快数
int CheckValide(int curPosX, int curPosY, BOOL bCurTeris[4][4]);   //给定一个矩阵，查看是否合法
int selectDiffculty(HWND hWnd, int dif);
int selectLayOut(HWND hWnd, int layout);

//常量声明
const int BORDER_X = 10;//以常量形式定义BORDER_X为10
const int BORDER_Y = 10;//以常量形式定义BORDER_Y为10
const int SCREEN_LEFT_X = 300 + BORDER_X;//定义常量SCREEN_LEFT_X为300 + BORDER_X
const int SCREEN_RIGHT_X = 180 + BORDER_X * 2;//定义常量SCREEN_RIGHT_X为180 + BORDER_X
const int SCREEN_X = SCREEN_LEFT_X + SCREEN_RIGHT_X;//定义常量SCREEN_X 为SCREEN_LEFT_X + SCREEN_RIGHT_X;
const BOOL state_teris[][4][4] =
{
	{ { 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,1 },{ 0,0,0,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 0,0,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,0,0 },{ 1,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,1 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
};//给出矩阵


//全局变量声明
bool g_hasBlocked[50][50];//定义
RECT rc_left, rc_right, rc_right_top, rc_right_bottom, rc_main;//声明页面格式
int g_speed = 300;//声明移动速度
int t_speed = 300;//声明移动速度
BOOL bCurTeris[4][4];//当前方块大小
BOOL bNextCurTeris[4][4];//下一个掉落方块大小
int curPosX, curPosY;//声明方块坐标
int rd_seed = 1995421;//初始化速度
int tPre = 0, tCur;//定义前一个方块和当前方块
int GAME_STATE = 0;//控制游戏开始
int GAME_SCORE = 0;//初始化得分
int GAME_DIFF = 1;//初始化差速
int NUM_X = 10;//声明横坐标方向方快数
int NUM_Y = 20;//声明纵坐标方向方快数
int BLOCK_SIZE = 30;//声明方块尺寸