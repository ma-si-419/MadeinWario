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
	//�O���t�B�b�N�̃��[�h
	m_handle = LoadGraph("data/finger.png");//�w�̉摜�̃_�E�����[�h
	m_clearHandle = LoadGraph("data/clear.png");//�N���A�V�[���̉摜�̃_�E�����[�h
	m_failedHandle = LoadGraph("data /failed.png");
	assert(m_handle != -1);		//�O���t�B�b�N�̃��[�h�Ɏ��s������~�܂�
	assert(m_clearHandle != -1);//�O���t�B�b�N�̃��[�h�Ɏ��s������~�܂�
	//�v���C���[�̈ړ����x��ݒ肷��
	m_speedX = kSpeed;
	m_speedY = kSpeed;
}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE) && m_spaceFlag)
	{
		//�X�y�[�X���񉟂����Ȃ����߂̏���
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
	//���w�̍��W���Ƃ葱����
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
	DrawFormatString(0, 70, GetColor(0, 0, 0), "%.0f��%.0f�ł�", m_posX, m_posY);
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
	//�O���t�B�b�N�̕��ƍ������擾����
	GetGraphSize(m_handle, &m_width, &m_height);
}
