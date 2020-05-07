#pragma once

///GUIボタン（アニメーション）
class Button {
	private:
		  Rect button;//ボタン用の図形
		ColorF color,basicC,basicHighC;//ボタンの色、通常色
		 Point pos;//文字の位置
		String text;//文字の内容
		  Font font;//文字
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
		//表示するテキスト、フォントの大きさ、位置(中心)、横、縦
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
			//マウスオーバーのアニメーション
			if (button.mouseOver() && color.r <= basicHighC.r)//カーソルと接触かつ色が明るすぎなければ
				color += ColorF(0.1);//明るくする
			else if (color.r >= basicC.r)//カーソルがなく暗すぎなければ
				color -= ColorF(0.1);//暗くする
			button.draw(color);
			font(text).drawAt(pos,ColorF(1.0)-color);
			return button.leftClicked();
		}
		void setText(String s) { text = s; }
};