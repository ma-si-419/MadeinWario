#pragma once
class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw() const;

	void SetGraphHandle(int handle);

	//�����蔻����Ƃ邽�߂ɕK�v�ȕϐ�
	float GetLeft() const;
	float GetRight() const;
private:

	//�O���t�B�b�N������ϐ�
	int m_handle;
	//�O���t�B�b�N�̃T�C�Y
	int m_width;
	int m_height;
	//�v���C���[�̃|�W�V����
	float m_posX;
	float m_posY;
	//�v���C���[�̈ړ����x
	float m_speedX;
	float m_speedY;
	//�X�y�[�X�������ꂽ�����f����ϐ�
	bool m_spaceFlag;

};

