#include "Player.h"
#include"DxLib.h"
#include <cassert>
#include"Game.h"

namespace
{
	//移動速度
	constexpr float kSpeed = 8.0f;
}
Player::Player() :
	m_handle(-1),
	m_clearHandle(-1),
	m_failedHandle(-1),
	m_height(0),
	m_width(256),
	m_posX(240),
	m_posY(240),
	m_speedX(0),
	m_speedY(0),
	m_spaceFlag(true),
	m_clearFlag(false),
	m_failedFlag(false)
{
}

Player::~Player()
{
}

void Player::Init()
{
	//グラフィックのロード
	m_handle = LoadGraph("data/finger.png");//指の画像のダウンロード
	m_clearHandle = LoadGraph("data/clear.png");//クリアシーンの画像のダウンロード
	m_failedHandle = LoadGraph("data /failed.png");
	assert(m_handle != -1);		//グラフィックのロードに失敗したら止まる
	assert(m_clearHandle != -1);//グラフィックのロードに失敗したら止まる
	//プレイヤーの移動速度を設定する
	m_speedX = kSpeed;
	m_speedY = kSpeed;
}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE) && m_spaceFlag)
	{
		//スペースを二回押させないための処理
		m_spaceFlag = false;

	}


	if (m_spaceFlag)//スペースボタンが押されるまで
	{
		//横方向に移動させ続ける
		m_posX += m_speedX;
		if (m_posX < 0.0f)//もし左側の壁にぶつかったら
		{
			m_speedX *= -1;//壁に跳ね返る
		}
		if (m_posX > Game::kScreenWidth - m_width)//もし右側の壁にぶつかったら
		{
			m_speedX *= -1;//壁に跳ね返る
		}
	}
	else//スペースボタンが押されたら
	{
		m_posY -= m_speedY;//縦方向に移動する
	}
	//小指の座標をとり続ける
	if (m_posX > 88 && m_posX < 110 && m_posY < 100)
	{
		m_speedY = 0;
		m_clearFlag = true;
	}
	else if(m_posX >155 && m_posX < 193 && m_posY < 100)
	{
		m_speedY = 0;
		m_clearFlag = true;
	}
	else if (m_posY < 90)
	{
		m_speedY = 0;
		m_failedFlag = true;
	}
	

}

void Player::Draw() const
{
	assert(m_handle != -1);
	DrawFormatString(0, 70, GetColor(0, 0, 0), "%.0fと%.0fです", m_posX, m_posY);
	DrawGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, true);
	if (m_clearFlag)
	{
		DrawGraph(120, 160, m_clearHandle, true);
	}
	if (m_failedFlag)
	{
		DrawGraph(200, 0, m_failedHandle, true);
	}

}

void Player::SetGraphHandle(int handle)
{
	m_handle = handle;
	//グラフィックの幅と高さを取得する
	GetGraphSize(m_handle, &m_width, &m_height);
}
