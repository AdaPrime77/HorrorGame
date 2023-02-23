#include "prologue.hpp"

#include "DxLib.h"

/* Prologue�֐��p�̕ϐ� */
static int prologue_counter;

/* ���̃t�@�C���̂��߂̏������֐� */
bool InitializePrologue(void){
	prologue_counter = 0;
return 0;
}

/* �v�����[�O�\���֐� �v�����[�O���I�������1��Ԃ� �I�����Ă��Ȃ���0��Ԃ� */
bool Prologue(bool push_key[256], int one_key[256]){

	if(one_key[KEY_INPUT_SPACE] == 1){
		prologue_counter++;
	}
	
	if(prologue_counter == 1){
		DrawString(10, 10, "20xx�N 3�� 7��", GetColor(255, 255, 255));
	}else if(prologue_counter == 2){
		DrawString(10, 10, "20xx�N 3�� 7��", GetColor(255, 255, 255));
		DrawString(50, 50, "���Z�ɒʂ��~�J�͈ٕςɋC�t�����B", GetColor(255, 255, 255));
	}else if(prologue_counter == 3){
		DrawString(10, 10, "20xx�N 3�� 7��", GetColor(255, 255, 255));
		DrawString(50, 50, "���Z�ɒʂ��~�J�͈ٕςɋC�t�����B", GetColor(255, 255, 255));
		DrawString(50, 90, "�����ꏏ�ɒʊw����F�l�����[�R��", GetColor(255, 255, 255));
	}else if(prologue_counter == 4){
		DrawString(10, 10, "20xx�N 3�� 7��", GetColor(255, 255, 255));
		DrawString(50, 50, "���Z�ɒʂ��~�J�͈ٕςɋC�t�����B", GetColor(255, 255, 255));
		DrawString(50, 90, "�����ꏏ�ɒʊw����F�l�����[�R��", GetColor(255, 255, 255));
		DrawString(50, 130, "���������҂����킹�ꏊ�Ɍ���Ȃ��̂��B", GetColor(255, 255, 255));
	}else if(prologue_counter == 5){
		DrawString(10, 10, "20xx�N 3�� 7��", GetColor(255, 255, 255));
		DrawString(50, 50, "���Z�ɒʂ��~�J�͈ٕςɋC�t�����B", GetColor(255, 255, 255));
		DrawString(50, 90, "�����ꏏ�ɒʊw����F�l�����[�R��", GetColor(255, 255, 255));
		DrawString(50, 130, "���������҂����킹�ꏊ�Ɍ���Ȃ��̂��B", GetColor(255, 255, 255));
		DrawString(50, 170, "�~�J������ƒm�����̂͂��ꂩ�炷���������B", GetColor(255, 255, 255));
	}else if(prologue_counter == 6){
		DrawString(10, 10, "20xx�N 3�� 7��", GetColor(255, 255, 255));
		DrawString(50, 50, "���Z�ɒʂ��~�J�͈ٕςɋC�t�����B", GetColor(255, 255, 255));
		DrawString(50, 90, "�����ꏏ�ɒʊw����F�l�����[�R��", GetColor(255, 255, 255));
		DrawString(50, 130, "���������҂����킹�ꏊ�Ɍ���Ȃ��̂��B", GetColor(255, 255, 255));
		DrawString(50, 170, "�~�J������ƒm�����̂͂��ꂩ�炷���������B", GetColor(255, 255, 255));
		DrawString(50, 210, "�͂��߂͕a�C���������Ǝv���Ă����B", GetColor(255, 255, 255));
	}else if(prologue_counter == 7){
		DrawString(10, 10, "20xx�N 3�� 7��", GetColor(255, 255, 255));
		DrawString(50, 50, "���Z�ɒʂ��~�J�͈ٕςɋC�t�����B", GetColor(255, 255, 255));
		DrawString(50, 90, "�����ꏏ�ɒʊw����F�l�����[�R��", GetColor(255, 255, 255));
		DrawString(50, 130, "���������҂����킹�ꏊ�Ɍ���Ȃ��̂��B", GetColor(255, 255, 255));
		DrawString(50, 170, "�~�J������ƒm�����̂͂��ꂩ�炷���������B", GetColor(255, 255, 255));
		DrawString(50, 210, "�͂��߂͕a�C���������Ǝv���Ă����B", GetColor(255, 255, 255));
		DrawString(50, 250, "�ł�", GetColor(255, 255, 255));
	}else if(prologue_counter == 8){
		DrawString(10, 10, "20xx�N 3�� 7��", GetColor(255, 255, 255));
		DrawString(50, 50, "���Z�ɒʂ��~�J�͈ٕςɋC�t�����B", GetColor(255, 255, 255));
		DrawString(50, 90, "�����ꏏ�ɒʊw����F�l�����[�R��", GetColor(255, 255, 255));
		DrawString(50, 130, "���������҂����킹�ꏊ�Ɍ���Ȃ��̂��B", GetColor(255, 255, 255));
		DrawString(50, 170, "�~�J������ƒm�����̂͂��ꂩ�炷���������B", GetColor(255, 255, 255));
		DrawString(50, 210, "�͂��߂͕a�C���������Ǝv���Ă����B", GetColor(255, 255, 255));
		DrawString(50, 250, "�ł�", GetColor(255, 255, 255));
		DrawString(50, 290, "�����[�R�͍s���s���ɂȂ��Ă����B", GetColor(255, 255, 255));
	}else if(prologue_counter >= 9){
		return 1;
	}

return 0;	
}