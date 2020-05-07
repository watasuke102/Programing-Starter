#pragma once

///GUI�{�^���i�A�j���[�V�����j
class Button {
	private:
		  Rect button;//�{�^���p�̐}�`
		ColorF color,basicC,basicHighC;//�{�^���̐F�A�ʏ�F
		 Point pos;//�����̈ʒu
		String text;//�����̓��e
		  Font font;//����
	public:
		Button(){
			color  = ColorF(0.2);
			basicC = ColorF(0.2);
			basicHighC = ColorF(1.0);
			pos    = Point(100, 50);
			text   = U"text";
			font   = Font(50);
			button = Rect(Arg::center(pos), 200, 100);
		}
		//�\������e�L�X�g�A�t�H���g�̑傫���A�ʒu(���S)�A���A�c
		Button(String tempText,int size, Point tempPos, int width, int height) {
			color  = ColorF(0.2);
			basicC = ColorF(0.2);
			basicHighC = ColorF(1.0);
			pos    = tempPos;
			text   = tempText;
			font   = Font(size);
			button = Rect(Arg::center(pos), width, height);
		}
		bool update() {
			//button = Rect(Arg::center(pos),button.w,button.h);
			//�}�E�X�I�[�o�[�̃A�j���[�V����
			if (button.mouseOver() && color.r <= basicHighC.r)//�J�[�\���ƐڐG���F�����邷���Ȃ����
				color += ColorF(0.1);//���邭����
			else if (color.r >= basicC.r)//�J�[�\�����Ȃ��Â����Ȃ����
				color -= ColorF(0.1);//�Â�����
			button.draw(color);
			font(text).drawAt(pos,ColorF(1.0)-color);
			return button.leftClicked();
		}
		void setText(String s) { text = s; }
};