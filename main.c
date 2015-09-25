//
//  main.c
//  StrengthenSimulation
//
//  Created by Rui Wu on 15/9/9.
//  Copyright (c) 2015年 Rui Wu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    
    srand((unsigned)time(NULL));
    
    //模拟次数
    unsigned long SimTimes = 100000000;
    
    //强化成功概率
    float StrengthenProbability[10] =
        {
            1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1
        };
    
    //强化所需材料数量
    unsigned int StrengthenMaterial[10] =
        {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };
    
    //目标装备等级
    unsigned int targetLevel = 8;
    
    
    //当前数据
    unsigned int curLevel = 1;
    unsigned long needMaterial = 0;
    unsigned int targetQuantity = 0;
    
    
    for (int i = 1; i < SimTimes + 1; i++) {
        
        int rd = rand()%1000000 ;
        double dbRd = (double)rd/1000000 ;
        
        if (dbRd < StrengthenProbability[curLevel - 1]) {
            needMaterial += StrengthenMaterial[curLevel - 1];
            curLevel += 1;
            if (curLevel >= targetLevel) {
                targetQuantity += 1;
                curLevel = 1;
            }
        }
        else if (curLevel > 2){
            needMaterial += StrengthenMaterial[curLevel - 1];
            curLevel -= 1;
        }
        else {
            needMaterial += StrengthenMaterial[curLevel - 1];
        }
        
    }
    unsigned int result = (unsigned int)needMaterial/targetQuantity;
    
    printf("平均每消耗%u个材料获得一个等级%u的装备。",result, targetLevel);
    
    return 0;
}
