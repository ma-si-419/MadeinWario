#include "Player.h"
#include"DxLib.h"
#include <cassert>
#include"Game.h"

namespace
{
	//�ړ����x
	constexpr float kSpeed = 8.0f;
}
Player::Player() :
	m_handle(-1),
	m_height(0),
	m_width(256),
	m_posX(240),
	m_posY(240),
	m_speedX(0),
	m_speedY(0),
	m_spaceFlag(true)
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
	m_speedX = kSpeed;
	m_speedY = kSpeed;
}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE) && m_spaceFlag)
	{
		m_spaceFlag = false;
	}


	if (m_spaceFlag)//�X�y�[�X�{�^�����������܂�
	{
		//�������Ɉړ�����������
		m_posX += m_speedX;
		if (m_posX < 0.0f)//���������̕ǂɂԂ�������
		{
			m_speedX *= -1;//�ǂɒ��˕Ԃ�
		}
		if (m_posX > Game::kScreenWidth - m_width)//�����E���̕ǂɂԂ�������
		{
			m_speedX *= -1;//�ǂɒ��˕Ԃ�
		}
	}
	else//�X�y�[�X�{�^���������ꂽ��
	{
		m_posY -= m_speedY;//�c�����Ɉړ�����
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
