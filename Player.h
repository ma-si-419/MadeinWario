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
private:

	//�O���t�B�b�N������ϐ�
	int m_handle;
	int m_clearHandle;
	int m_failedHandle;
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
	//�������������f����ϐ�
	bool m_clearFlag;
	bool m_failedFlag;
};

