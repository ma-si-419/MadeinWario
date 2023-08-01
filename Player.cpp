#include "Player.h"
#include"DxLib.h"
#include <cassert>
#include"Game.h"

namespace
{
	//�ړ����x
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
	//�O���t�B�b�N�̃��[�h
	m_handle = LoadGraph("data/finger.png");
	assert(m_handle != -1);		//�O���t�B�b�N�̃��[�h�Ɏ��s������~�܂�
	//�v���C���[�̈ړ����x��ݒ肷��
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
	//�O���t�B�b�N�̕��ƍ������擾����
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
