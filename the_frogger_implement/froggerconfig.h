#ifndef FROGGERCONFIG_H
#define FROGGERCONFIG_H

#include <QtMath>

namespace frogger {
    enum Screen{
        SScreen,
        GScreen,
        GOScreen,
    };

    const int width = 1920;
    const int height = 1080;
    const int FPS = 33;

    const qreal X_SB_COEF = 0.75;
    const qreal Y_SB_COEF = 0.45;
    const qreal INCREASE_SB_COEF = 1.10;
    const qreal DECREASE_SB_COEF = (1-(INCREASE_SB_COEF-1));

    const qreal X_IN_COEF = 0.61;
    const qreal Y_IN_COEF = 0.70;

    const qreal X_SCENARIO_WCOEF = 0.9;
    const qreal Y_SCENARIO_HCOEF = 0.8;
    const qreal X_SCENARIO_COEF = (1-X_SCENARIO_WCOEF)*0.5;
    const qreal Y_SCENARIO_COEF = (1-Y_SCENARIO_HCOEF)*0.15;
    const qreal NR_L = 11; // 11 vias = 11 linhas
    const qreal NR_C = 11; // 6 vitória-régias + 5 espaços entre elas = 12 colunas
    const qreal GS_LIMITE_V = (X_SCENARIO_WCOEF*width);
    const qreal GS_LIMITE_H = (Y_SCENARIO_HCOEF*height);
    const qreal BASE_PASSO_Y = (Y_SCENARIO_HCOEF*height/NR_L);
    const qreal BASE_PASSO_X = (X_SCENARIO_WCOEF*width/NR_C);
    const qreal Y_CALCADA_UM = 1/NR_L;
    const qreal Y_RUA_UM = 2/NR_L;

    const qreal MVB_OFFSET_X = 5;

}

#endif // FROGGERCONFIG_H
