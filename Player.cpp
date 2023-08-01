#include "Player.h"
#include"DxLib.h"
#include <cassert>
#include"Game.h"

namespace
{
	//移動速度
	constexpr float kSpeed = 8.0f;
}
Player::Player():
	m_handle(-1),
	m_height(0),
	m_width(256),
	m_posX(240),
	m_posY(240),
	m_speed(0)
{
}

Player::~Player()
{
}

void Player::Init()
{
	//グラフィックのロード
	m_handle = LoadGraph("data/finger.png");
	assert(m_handle != -1);		//グラフィックのロードに失敗したら止まる
	//プレイヤーの移動速度を設定する
	m_speed = kSpeed;
}

void Player::Update()
{
	m_posX += m_speed;
	if (m_posX < 0.0f)
	{
		m_speed *= -1;
	}
	if (m_posX > Game::kScreenWidth - m_width)
	{
		m_speed *= -1;
	}
}

void Player::Draw() const
{
	assert(m_handle != -1);
	DrawGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, true);
}

void Player::SetGraphHandle(int handle)
{
	m_handle = handle;
	//グラフィックの幅と高さを取得する
	GetGraphSize(m_handle, &m_width, &m_height);
}

float Player::GetLeft() const
{
	return m_posX;
}

float Player::GetRight() const
{
	return m_posX + m_width;
}
