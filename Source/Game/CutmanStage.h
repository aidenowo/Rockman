#pragma once
#include <fstream>
#include "../Library/audio.h"
namespace game_framework {
	class CutmanStage
	{
	public:
		CutmanStage() {
			// map initialize
			this->readFile();
			rockman.setmap(map);
			cutman.setmap(map);
			// 初始化怪物
			enemyContainer.push_back(new Heli(280 * 2, 2110 * 2));
			enemyContainer.push_back(new Heli(428 * 2, 2178 * 2));
			enemyContainer.push_back(new Heli(448 * 2, 2133 * 2));
			enemyContainer.push_back(new Heli(1888 * 2, 70 * 2)); // y = 72會炸，怪物最好不要跟人同一個平台
			enemyContainer.push_back(new Heli(1928 * 2, 132 * 2));
			enemyContainer.push_back(new Heli(1947 * 2, 79 * 2));
			enemyContainer.push_back(new Beak(816 * 2, 2112 * 2, 0)); //param 3: 0代表面左，1代表面右
			enemyContainer.push_back(new Beak(944 * 2, 2159 * 2, 0));
			enemyContainer.push_back(new Beak(976 * 2, 1936 * 2, 0));
			enemyContainer.push_back(new Beak(880 * 2, 1872 * 2, 0)); 
			enemyContainer.push_back(new Beak(912 * 2, 1840 * 2, 0)); 
			enemyContainer.push_back(new Beak(832 * 2, 1712 * 2, 1)); 
			enemyContainer.push_back(new Beak(880 * 2, 1648 * 2, 0));
			enemyContainer.push_back(new Beak(944 * 2, 1584 * 2, 0));
			enemyContainer.push_back(new Beak(880 * 2, 1488 * 2, 1));
			enemyContainer.push_back(new Beak(944 * 2, 1360 * 2, 0));
			enemyContainer.push_back(new Beak(912 * 2, 1312 * 2, 0));
			// 慢慢調delay
			enemyContainer.push_back(new Octopus(1344 * 2, 1184 * 2, 1344 * 2, 1200 * 2, 800)); // 800
			enemyContainer.push_back(new Octopus(1376 * 2, 1120 * 2, 1376 * 2, 1152 * 2, 1200)); // 1200
			enemyContainer.push_back(new Octopus(1456 * 2, 1152 * 2, 1360 * 2, 1152 * 2, 0)); 

			enemyContainer.push_back(new Octopus(1488 * 2, 896 * 2, 1312 * 2, 896 * 2, 0)); 
			enemyContainer.push_back(new Octopus(1392 * 2, 864 * 2, 1312 * 2, 864 * 2, 0));
			enemyContainer.push_back(new Octopus(1360 * 2, 896 * 2, 1360 * 2, 944 * 2, 2000));
			enemyContainer.push_back(new Octopus(1344 * 2, 832 * 2, 1456 * 2, 832 * 2, 2000));

			enemyContainer.push_back(new Octopus(1408 * 2, 688 * 2, 1408 * 2, 704 * 2, 2000));
			enemyContainer.push_back(new Octopus(1392 * 2, 672 * 2, 1376 * 2, 672 * 2, 0));
			enemyContainer.push_back(new Octopus(1456 * 2, 608 * 2, 1312 * 2, 608 * 2, 0));
			enemyContainer.push_back(new Octopus(1488 * 2, 576 * 2, 1312 * 2, 576 * 2, 0));

			enemyContainer.push_back(new Octopus(1328 * 2, 416 * 2, 1312 * 2, 416 * 2, 0));
			enemyContainer.push_back(new Octopus(1328 * 2, 368 * 2, 1328 * 2, 448 * 2, 2000));
			enemyContainer.push_back(new Octopus(1408 * 2, 384 * 2, 1456 * 2, 384 * 2, 2000));
			enemyContainer.push_back(new Octopus(1472 * 2, 288 * 2, 1472 * 2, 336 * 2, 2000));
			enemyContainer.push_back(new Octopus(1312 * 2, 320 * 2, 1488 * 2, 320 * 2, 2000));
			
			enemyContainer.push_back(new Screw(2480 * 2, 912 * 2, 0, 1));
			enemyContainer.push_back(new Screw(2720 * 2, 864 * 2, 1, 1));
			enemyContainer.push_back(new Screw(2856 * 2, 912 * 2, 0, 1));

		};
		~CutmanStage() {
			for (size_t i = 0; i < enemyContainer.size(); i++)
			{
				delete enemyContainer[i];
			}
		};
		void OnInit() {
			cutman_stage.LoadBitmapByString({ "resources/stage/CutManStage.bmp" });
			rockman_blood.LoadBitmapByString({ "resources/rockman/blood/blood0.bmp",
											   "resources/rockman/blood/blood1.bmp", 
												"resources/rockman/blood/blood2.bmp", 
												"resources/rockman/blood/blood3.bmp", 
												"resources/rockman/blood/blood4.bmp", 
												"resources/rockman/blood/blood5.bmp", 
												"resources/rockman/blood/blood6.bmp", 
												"resources/rockman/blood/blood7.bmp", 
												"resources/rockman/blood/blood8.bmp", 
												"resources/rockman/blood/blood9.bmp", 
												"resources/rockman/blood/blood10.bmp", 
												"resources/rockman/blood/blood11.bmp", 
												"resources/rockman/blood/blood12.bmp", 
												"resources/rockman/blood/blood13.bmp", 
												"resources/rockman/blood/blood14.bmp",
												"resources/rockman/blood/blood15.bmp",
												"resources/rockman/blood/blood16.bmp",
												"resources/rockman/blood/blood17.bmp",
												"resources/rockman/blood/blood18.bmp",
												"resources/rockman/blood/blood19.bmp",
												"resources/rockman/blood/blood20.bmp",
												"resources/rockman/blood/blood21.bmp",
												"resources/rockman/blood/blood22.bmp",
												"resources/rockman/blood/blood23.bmp",
												"resources/rockman/blood/blood24.bmp",
												"resources/rockman/blood/blood25.bmp",
												"resources/rockman/blood/blood26.bmp",
												"resources/rockman/blood/blood27.bmp",
												"resources/rockman/blood/blood28.bmp",});
			rockman_blood.SetTopLeft(48, 50);
			stageShine.LoadBitmapByString({
				"resources/stage/cutmanStage/cutmanStageShine.bmp",
				"resources/stage/purple.bmp",
				"resources/stage/cutmanStage/cutmanStageShine.bmp",
				"resources/stage/purple.bmp",
				"resources/stage/cutmanStage/cutmanStageShine.bmp",
				"resources/stage/purple.bmp",
				"resources/stage/cutmanStage/cutmanStageShine.bmp",
				"resources/stage/purple.bmp",
				"resources/stage/cutmanStage/cutmanStageShine.bmp",
				"resources/stage/purple.bmp",
				"resources/stage/cutmanStage/cutmanStageShine.bmp",
				"resources/stage/purple.bmp",
				}, RGB(128, 0, 128));
			stageShine.SetTopLeft(0, 0);
			stageShine.SetAnimation(100, true);

			bossGate[0].LoadBitmapByString({
				"resources/stage/cutmanStage/gate3/bossStageGate0.bmp",
				"resources/stage/cutmanStage/gate3/bossStageGate1.bmp",
				"resources/stage/cutmanStage/gate3/bossStageGate2.bmp",
				"resources/stage/cutmanStage/gate3/bossStageGate3.bmp",
				"resources/stage/cutmanStage/gate3/bossStageGate4.bmp",
				});
			bossGate[0].SetTopLeft(0, 192);
			bossGate[0].SetAnimation(100, true);
			bossGate[1].LoadBitmapByString({
				"resources/stage/cutmanStage/gate1/tunnelGate0.bmp",
				"resources/stage/cutmanStage/gate1/tunnelGate1.bmp",
				"resources/stage/cutmanStage/gate1/tunnelGate2.bmp",
				"resources/stage/cutmanStage/gate1/tunnelGate3.bmp",
				"resources/stage/cutmanStage/gate1/tunnelGate4.bmp",
				});
			bossGate[1].SetTopLeft(2272 * 2, 864 * 2);
			bossGate[1].SetAnimation(100, true);
			bossGate[2].LoadBitmapByString({
				"resources/stage/cutmanStage/gate2/bossStageGate4.bmp",
				"resources/stage/cutmanStage/gate2/bossStageGate3.bmp",
				"resources/stage/cutmanStage/gate2/bossStageGate2.bmp",
				"resources/stage/cutmanStage/gate2/bossStageGate1.bmp",
				"resources/stage/cutmanStage/gate2/bossStageGate0.bmp",
				});
			bossGate[2].SetTopLeft(3056 * 2, 864 * 2);
			bossGate[2].SetAnimation(100, true);

			cutman_blood.LoadBitmapByString({
				{ "resources/enemy/cutman/blood/blood0.bmp" },
				{ "resources/enemy/cutman/blood/blood1.bmp" },
				{ "resources/enemy/cutman/blood/blood2.bmp" },
				{ "resources/enemy/cutman/blood/blood3.bmp" },
				{ "resources/enemy/cutman/blood/blood4.bmp" },
				{ "resources/enemy/cutman/blood/blood5.bmp" },
				{ "resources/enemy/cutman/blood/blood6.bmp" },
				{ "resources/enemy/cutman/blood/blood7.bmp" },
				{ "resources/enemy/cutman/blood/blood8.bmp" },
				{ "resources/enemy/cutman/blood/blood9.bmp" },
				{ "resources/enemy/cutman/blood/blood10.bmp" },
				{ "resources/enemy/cutman/blood/blood11.bmp" },
				{ "resources/enemy/cutman/blood/blood12.bmp" },
				{ "resources/enemy/cutman/blood/blood13.bmp" },
				{ "resources/enemy/cutman/blood/blood14.bmp" },
				{ "resources/enemy/cutman/blood/blood15.bmp" },
				{ "resources/enemy/cutman/blood/blood16.bmp" },
				{ "resources/enemy/cutman/blood/blood17.bmp" },
				{ "resources/enemy/cutman/blood/blood18.bmp" },
				{ "resources/enemy/cutman/blood/blood19.bmp" },
				{ "resources/enemy/cutman/blood/blood20.bmp" },
				{ "resources/enemy/cutman/blood/blood21.bmp" },
				{ "resources/enemy/cutman/blood/blood22.bmp" },
				{ "resources/enemy/cutman/blood/blood23.bmp" },
				{ "resources/enemy/cutman/blood/blood24.bmp" },
				{ "resources/enemy/cutman/blood/blood25.bmp" },
				{ "resources/enemy/cutman/blood/blood26.bmp" },
				{ "resources/enemy/cutman/blood/blood27.bmp" },
				{ "resources/enemy/cutman/blood/blood28.bmp" },
				});
			cutman_blood.SetTopLeft(80, 50);
			cutman_blood.SetAnimation(75, true);
			
			cutman_stage.SetTopLeft(-stage_x, -stage_y);
			rockman.OnInit(stage_x, stage_y);
			// cutman
			cutman.OnInit();
			for (size_t i = 0; i < enemyContainer.size(); i++)
			{
				enemyContainer[i]->OnInit();
			}
		};
		void OnMove() {

			int rockmanX = rockman.getX();
			int rockmanY = rockman.getY();
			// 判斷transition state的更換
			if (transitionState == -1) { // -1代表在死亡動畫
				if (rockman.deadAnimationDone()) { //死亡動畫結束
					// 回到正常的transition，順便重製
					if (savePoint == 2) {
						transitionState = 30;
						CAudio::Instance()->Play(0, true);
					}
					else {
						transitionState = 0;
						CAudio::Instance()->Play(0, true);
					}
					if (rockman.getLives()-1 > 0) { // 因為到onbegin才會扣命，所以這邊判斷會延遲，要扣1
						this->OnBeginState(savePoint);
					}
					else {
						// game over
						// TODO 加入重製Onbegin
						gameState = 2;
					}
				}
			}
			else if (((rockmanY + 12) / 512) != (stage_y / 512)) { 
				//除以512為了檢查是否在同一層
				// case 1 洛克人在上面一層 -> (rockmanY + 12) / 512 < (stage_y / 512)
				if (((rockmanY + 12) / 512) < (stage_y / 512)) {
					transitionState = 1; // 1 代表向上轉場
				}
				// case 2  洛克人在下面一層 -> (rockmanY + 12) / 512 > (stage_y / 512)
				else {
					transitionState = 2; // 2 代表向上轉場
				}
			}
			else if(map[rockmanY / 32][(rockmanX + 2 * (24 - 1 - 4)) / 32] == 4){
				if (transitionState == 30) {
					transitionState = 31; //進王關transition
					CAudio::Instance()->Play(17, false);
				}
				else if (transitionState == 0) {
					transitionState = 28; //進王關廊道transition
					CAudio::Instance()->Play(17, false);
				}
			}

			rockman.OnMove(stage_x, stage_y, transitionState);
			// cutman
			cutman.OnMove(stage_x, stage_y, rockmanX, rockmanY, transitionState);

			// 根據不同的transitionState判斷敵人碰撞跟OnMove
			
			if (transitionState == 0 || transitionState == 30) {
				for (size_t i = 0; i < enemyContainer.size(); i++)
				{
					enemyContainer[i]->OnMove(rockmanX, rockmanY, stage_x, stage_y);
				}
				for (size_t i = 0; i < enemyContainer.size(); i++)
				{
					// enemyContainer[i]->OnMove(rockmanX, rockmanY, stage_x, stage_y);
					if (enemyContainer[i]->getIsActivate()) { //怪物is acitivated
						if (enableBeenHit) {
							if (!rockman.getIsHit() && enemyContainer[i]->successfullyAttack(rockman.getCurrentBitmap())) {
								// 沒被攻擊中，而且被打到
								// 可以呼叫怪物的isAttackFromRight()，set給rockman
								CAudio::Instance()->Play(7, false);
								rockman.setIsHit();
								rockman.decreaseBlood(enemyContainer[i]->getDamage());
								rockman.setIsAttackedFromRight(enemyContainer[i]->isAttackFromRight());
							}
						}

						for (int j = 0; j < 3; j++)
						{
							if (rockman.getIsShot(j)) {
								if (enemyContainer[i]->beenAttacked(rockman.getBullet(j))) {
									rockman.setIsShotfalse(j);
								}
							}
						}

					}
				}
			}
			else if (transitionState == 40) {
				if (enableBeenHit) {
					if (!rockman.getIsHit() && cutman.successfullyAttack(rockman.getCurrentBitmap())) {
						// 沒被攻擊中，而且被打到
						// 可以呼叫怪物的isAttackFromRight()，set給rockman
						CAudio::Instance()->Play(7, false);
						rockman.setIsHit();
						rockman.decreaseBlood(cutman.getDamage());
						rockman.setIsAttackedFromRight(cutman.isAttackFromRight());
					}
				}
				for (int j = 0; j < 3; j++)
				{
					if (rockman.getIsShot(j)) {
						if (cutman.beenAttacked(rockman.getBullet(j))) {
							CAudio::Instance()->Play(5, false);
							rockman.setIsShotfalse(j);
						}
					}
				}
			}
			

			// 計算array index的一個小概念，供參
			//int index_x = stage_x/32; //最左邊的index : index_x
			//int index_y = stage_y/32; //最上面的index : index_y 
									  //最右邊的index : index_x + 16 //若 >= 208，不做array的access
									  //最下面的index : index_y + 16 //若 >= 144，不做array的access
			// cutmanStage camera
			if (transitionState == 0) {
				// 王關之前的camera
				// 每個and的註解，以符合所有情況，應該沒問題了
				// 1)第一個廊道前最後一張512*512的座標 = 4096
				// 2)檢查camera向右移動會不會超出地圖邊界
				// 3)因為最一開始的圖示貼在邊邊，x座標已經是0了，不能再去access -1 的index
				// 4)檢查除了開場以外的camera向左會不會超出地圖邊界
				if (stage_x < 4096 && map[stage_y / 32][(stage_x + 512 + 1) / 32] != -1
					&& rockman.getX() - 232 > 0 && map[stage_y / 32][(rockman.getX() - 232) / 32] != -1) {
					stage_x = rockman.getX() - 2 * 116;
				}
				// 我更改初始畫面到到廊道前，發現需要加上這個else if 不然會跑掉
				else if (stage_x > 0 && map[stage_y / 32][(stage_x - 1) / 32] != -1  //首先stage_x要先>0，避免out of range，再來要stage_x還沒到最左邊(左邊那格不為-1)，否則不動
					&& rockman.getX() + 280 < 4608 && map[stage_y / 32][(rockman.getX() + 280) / 32] != -1) { //首先洛克人+280要小於整張地圖最右邊，避免out of range，再來rockman要不在地圖那一層的最右邊的半張區塊
					stage_x = rockman.getX() - 2 * 116;
				}

				/* 不再需要按左右才追蹤，不符合camera的設計概念，棄用
			 if (leftPressed) {
				else if (stage_x > 0 && map[stage_y / 32][(stage_x-1)/32] != -1  //首先stage_x要先>0，避免out of range，再來要stage_x還沒到最左邊(左邊那格不為-1)，否則不動
					&& rockman.getX() + 280 < 4608 && map[stage_y / 32][(rockman.getX() + 280) / 32] != -1){ //首先洛克人+280要小於整張地圖最右邊，避免out of range，再來rockman要不在地圖那一層的最右邊的半張區塊
					stage_x = rockman.getX() - 2 * 116;
				}
			 }
				*/
			}
			else if (transitionState == 30) { 
				//廊道的camera
				// 因為很單純，所以直接寫死
				if ((stage_x < 5632 && rockman.getX() - 232 > 4608) || (stage_x > 4608 && rockman.getX() + 280 < 6144)) {
					stage_x = rockman.getX() - 2 * 116;
				}

			}
			else if (transitionState == 40) {

			}
			else { //轉場觸發
				if (transitionState == 1) { //向上轉場
					stage_y -= dy; //512
					if (stage_y % 512 == 0) { //總計位移64次
						transitionState = 0;
					}
				}
				else if (transitionState == 2) { //向下轉場
					stage_y += dy; //512;
					if (stage_y % 512 == 0) {
						transitionState = 0;
					}
				}
				else if (transitionState == 28) {
					bossGate[1].ToggleAnimation();
					transitionState = 29;
				}
				else if (transitionState == 29) {
					if (bossGate[1].IsAnimationDone()) {
						transitionState = 3;
					}
				}
				else if (transitionState == 3) { //進廊道的轉場
					stage_x += dx; //512;
					if ((stage_x / 512) != ((stage_x - dx) / 512)) { //換到下一張圖了
						stage_x = (stage_x / 512) * 512;
						transitionState = 30;
					}
				}
				else if (transitionState == 31) {
					bossGate[2].ToggleAnimation();
					transitionState = 32;
				}
				else if (transitionState == 32) {
					if (bossGate[2].IsAnimationDone()) {
						transitionState = 4;
					}
				}
				else if (transitionState == 4) {
					stage_x += dx; //512;
					if ((stage_x / 512) != ((stage_x - dx) / 512)) {
						stage_x = (stage_x / 512) * 512;
						CAudio::Instance()->Stop(0);
						CAudio::Instance()->Play(8, true);
						stageShine.ToggleAnimation();
						transitionState = 33;
					}
				}
				else if (transitionState == 33) {
					if (stageShine.IsAnimationDone()) {
						bossGate[0].ToggleAnimation();
						CAudio::Instance()->Play(17, false);
						transitionState = 34;
					}
				}
				else if (transitionState == 34) {
					if (bossGate[0].IsAnimationDone()) {
						//bossGate[0].SetFrameIndexOfBitmap(3);
						cutman_blood.ToggleAnimation();
						CAudio::Instance()->Pause();
						CAudio::Instance()->Play(9, false);
						transitionState = 35;
					}
				}
				else if (transitionState == 35) {
					if (cutman_blood.IsAnimationDone()) {
						CAudio::Instance()->Stop(9);
						CAudio::Instance()->Resume();
						transitionState = 40;
					}
				}
			// 40  is the state rockman can move
			}

			// 到達savePoint的判斷
			if (savePoint == 0 && stage_x == savePoint_stage[1][0] && stage_y <= savePoint_stage[1][1]) {
				savePoint = 1;
			}
			else if (savePoint == 1 && stage_x >= savePoint_stage[2][0] && stage_y == savePoint_stage[2][1]) {
				savePoint = 2;
			}
			cutman_stage.SetTopLeft(-stage_x, -stage_y);
			bossGate[1].SetTopLeft(2272 * 2 - stage_x, 864 * 2 - stage_y);
			bossGate[2].SetTopLeft(3056 * 2 - stage_x, 864 * 2 - stage_y);
			checkReset(); //TODO: 裡面需要一些判斷來決定要不要respawn(呼叫個別的onBeginState)
		};
		void Onshow() {
			cutman_stage.ShowBitmap(2);
			if (transitionState == 31 || transitionState == 32 || transitionState == 4) {
				bossGate[2].ShowBitmap(2);
			}
			else if (transitionState == 33) {
				stageShine.ShowBitmap(2);
			}
			if (transitionState == 28 || transitionState == 29 || transitionState == 3) {
				bossGate[1].ShowBitmap(2);
			}
			rockman.Onshow(stage_x, stage_y, transitionState); // 256*2是最邊邊，48是角色寬度
			cutman.OnShow(transitionState);

			// new edit

			if (33 <= transitionState && transitionState < 40) {
				inBossStage = true;
				cutman_blood.ShowBitmap(2);
			}
			else if (transitionState == 40 || (inBossStage && transitionState == -1)) {
				// TODO: 要注意如果blood < 0
				if (cutman.getBlood() >= 0)
					cutman_blood.SetFrameIndexOfBitmap(cutman.getBlood());
				else
					cutman_blood.SetFrameIndexOfBitmap(0);
				cutman_blood.ShowBitmap(2);
			}
			if (transitionState >= 34 || (inBossStage && transitionState == -1)) {
				bossGate[0].ShowBitmap(2);
			}
			if (transitionState == 0 || transitionState == 30) {
				for (size_t i = 0; i < enemyContainer.size(); i++)
				{
					enemyContainer[i]->OnShow();

				}
			}

			rockman_blood.SetFrameIndexOfBitmap(rockman.getBlood());
			rockman_blood.ShowBitmap(2);

			if (showlife == 1) {
				CDC *px = CDDraw::GetBackCDC();
				CTextDraw::ChangeFontLog(px, 13, "MMRock9", RGB(255, 255, 255));
				message = "LIFE x" + to_string(rockman.getLives());
				CTextDraw::Print(px, 180, 4, message.c_str());
				CDDraw::ReleaseBackCDC();
			}
		}
		void readFile() {
			// [144][208]
			// -1 for green bg
			// 0 for air 
			// 1 for wall
			// 2 for ladder
			// 3 for trap
			// 4 for gate-> trnasition
			// 5 for out of map->dead
			// 6 for laddertop
			ifstream ifs("Source/Maps/cutmanMap.txt");
			int num;
			for (int i = 0; i < 144; i++) {
				vector<int> temp;
				for (int j = 0; j < 208; j++) {
					ifs >> num;
					temp.push_back(num);
				}
				map.push_back(temp);
			}

			ifs.close();
		}
		void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
			rockman.OnKeyDown(nChar, nRepCnt, nFlags);
			if (nChar == VK_LEFT) {
				leftPressed = true;
			}
			if (nChar == VK_RIGHT) {
				rightPressed = true;
			}
			if (nChar == 0x52) {
				rockman.resetBlood();
			}
			if (nChar == 0x48) {
				if (showlife==0)
				{
					showlife = 1;
				}
				else {
					showlife = 0;
				}
			}
		}
		void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) {
			rockman.OnKeyUp(nChar, nRepCnt, nFlags);
			if (nChar == VK_LEFT) {
				leftPressed = false;
			}
			if (nChar == VK_RIGHT) {
				rightPressed = false;
			}
		}
		int getGamestate() {
			// 1過關、2OVER
			return gameState;
		}
		void OnBeginState(int point) {
			if (point == -1) {
				// 第一次進遊戲
				gameState = 0;
				savePoint = 0;
				transitionState = 0;
				stage_x = savePoint_stage[0][0];
				stage_y = savePoint_stage[0][1];
				rockman.OnBeginState(savePoint_rockman[0][0], savePoint_rockman[0][1], -1);
				cutman.OnBeginState();
				cutman_blood.SetFrameIndexOfBitmap(0); // 圖片也要歸零，不然下次進關卡看到的會先有血量
				inBossStage = false;
			}
			else if (point == 0) {
				transitionState = 0;
				stage_x = savePoint_stage[0][0];
				stage_y = savePoint_stage[0][1];
				rockman.OnBeginState(savePoint_rockman[0][0], savePoint_rockman[0][1], 0);

			}
			else if (point == 1) {
				transitionState = 0;
				stage_x = savePoint_stage[1][0];
				stage_y = savePoint_stage[1][1];
				rockman.OnBeginState(savePoint_rockman[1][0], savePoint_rockman[1][1], 1);
			}
			else if (point == 2) {
				// 在隧道的頭
				transitionState = 30;
				CAudio::Instance()->Stop(8);
				CAudio::Instance()->Play(0, true);
				stage_x = savePoint_stage[2][0];
				stage_y = savePoint_stage[2][1];
				rockman.OnBeginState(savePoint_rockman[2][0], savePoint_rockman[2][1], 2);
				cutman.OnBeginState();
				cutman_blood.SetFrameIndexOfBitmap(0); // 圖片也要歸零，不然下次進關卡看到的會先有血量
				inBossStage = false;
			}
			
			// 自從初始過後，不會再改變到
			// dx = 4;
			// dy = 8;
			
			// TODO 其他怪物的OnBeginState，可以塞入個別的savePoint，提高效能，或是全部都塞這
			enemyReset();
		}
		void enemyReset() {
			for (size_t i = 0; i < enemyContainer.size(); i++)
			{
				enemyContainer[i]->OnBeginState();
			}
			for (size_t i = 0; i < enemyContainer2.size(); i++)
			{
				enemyContainer2[i]->OnBeginState();
			}
		}
		void checkReset() {
			if (cutman.getBlood() <= 0) {
				//贏了
				if (cutman.deadAnimationDone()) {
					gameState = 1;
				}
			}
			else if (rockman.getBlood() <= 0 || rockman.getDieDirectly()) {
				// 只要血量低於0就是要啟動死亡動畫
				// 播放死亡音效，once
				transitionState = -1;
			}
			/*else if (rockman.getLives() > 0) {
				// blood
				int rockman_blood = rockman.getBlood();
				if ((rockman_blood <= 0 || rockman.getDieDirectly())) {
					transitionState = -1;
					// this->OnBeginState(savePoint);
				}
			}
			else {
				// game over
				transitionState = -1;
				
				if (rockman.canGameOver()) {
				 	gameState = 2;
				}
				
				// GotoGameState(GAME_STATE_OVER);
				// 要改狀態，讓mygame_run去跳state
			}*/
		}
		void setEnableBeenHit(bool state) {
			enableBeenHit = state;
		}
	private:
		// 先留著，雖然不知道有啥用ㄏ
		//vector<int> level_left = { 0 , 768 * 2, 768 * 2, 728 * 2, 768 * 2, 1280 * 2, 1280 * 2, 1280 * 2, 1280 * 2, 1792 * 2, 1792 * 2, 1792 * 2 };//3072王關
		//vector<int> level_top = { 2048 * 2 ,1792 * 2, 1536 * 2, 1280 * 2, 1024 * 2, 768 * 2, 512 * 2, 256 * 2, 0, 256 * 2, 512 * 2, 768 * 2 };//768王關
		
		// camera place chasing rockman at x-axis not y-axis 
		int dx = 4;
		int dy = 8;
		int transitionState = 0;
		int gameState = 0;
		bool inBossStage = false;
		bool enableBeenHit = true;
		// 初始點
		//int stage_x = 0;	//以整張圖的角度，所以setTopLeft要用負的
		//int stage_y = 4096; //以整張圖的角度，所以setTopLeft要用負的

		//剪刀窗戶的地方
		//int stage_x = 768*2;	//以整張圖的角度，所以setTopLeft要用負的
		//int stage_y = 1024*2; //以整張圖的角度，所以setTopLeft要用負的

		 int stage_x = 2048 * 2;
		 int stage_y = 768 * 2;
		 int showlife = 0;
		
		// 三個儲存點，之後再處理，X-Y要再對照一下
		int savePoint = 0;
		int savePoint_stage[3][2] = {
			{0, 4096}, 
			{2560, 1536}, 
			{4608, 1536}};
		int savePoint_rockman[3][2] = {
			{232, 4368},
			{2792, 1808},
			{4636, 1808}
		};
		bool leftPressed;
		bool rightPressed;

		string message;
		vector<Enemy*> enemyContainer;
		vector<Enemy*> enemyContainer2;

		vector<vector<int>> map;

		CMovingBitmap cutman_blood;
		CMovingBitmap cutman_stage;
		CMovingBitmap rockman_blood;
		CMovingBitmap stageShine;
		CMovingBitmap bossGate[3];

		Character rockman;
		Cutman cutman;
	};
}
