#include "Target.h"
#include"DxLib.h"
#include <cassert>
#include"Game.h"
Target::Target() :
	m_posX(200),
	m_posY(0)
{

}

Target::~Target()
{
}

void Target::Init()
{
	//グラフィックのロード
	m_handle = LoadGraph("data/nose.png");
	assert(m_handle != -1);		//グラフィックのロードに失敗したら止まる
}

void Target::Update()
{
}

void Target::Draw() const
{
	assert(m_handle != -1);
	DrawGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, true);
}

void Target::SetGraphHandle(int handle)
{
}

float Target::GetLeft() const
{
	return 0.0f;
}

float Target::GetRight() const
{
	return 0.0f;
}
