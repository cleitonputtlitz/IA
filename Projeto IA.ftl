PROJECT {
  NAME       = Projeto IA.ftl;
  TITLE      =salva;
  DATEFORMAT = YYYY.DD.MM;
  LASTCHANGE = 2014.02.09;
  CREATED    = 2014.02.09;
  SHELL      = ON_LINE;
  SHELLOPTIONS {
    ONLINE_REFRESHTIME  = 55;
    ONLINE_TIMEOUTCOUNT = 1100;
    ONLINE_CODE         = OFF;
    ONLINE_TRACE_BUFFER = (OFF, PAR(0));
    COMMENTS            = ON;
    FTL_BUFFER          = (OFF, PAR(1));
    PASSWORD            = OFF;
    PUBLIC_IO           = ON;
    FAST_CMBF           = OFF;
    FAST_COA            = ON;
    BTYPE               = DOUBLE;
    C_TYPE              = ANSI;
  } /* SHELLOPTIONS */
  MODEL {
    VARIABLE_SECTION {
      LVAR {
        NAME       = Media;
        BASEVAR    = Units;
        LVRANGE    = MIN(0.0), MAX(1.0),
                     MINDEF(0), MAXDEF(65535),
                     DEFAULT_OUTPUT(0.5);
        RESOLUTION = XGRID(0.1), YGRID(0.1),
                     SHOWGRID (ON), SNAPTOGRID(OFF);
        COLOR      = RED (255), GREEN (0), BLUE (0);
        INPUT      = CMBF;
        POS        = -168, -179;
        TERM {
          TERMNAME = Baixo;
          POINTS   = (0.0, 1.0),
                     (0.25, 1.0),
                     (0.4, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (255), GREEN (0), BLUE (0);
        }
        TERM {
          TERMNAME = Medio;
          POINTS   = (0.0, 0.0),
                     (0.25, 0.0),
                     (0.5, 1.0),
                     (0.75, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (128), BLUE (0);
        }
        TERM {
          TERMNAME = Alto;
          POINTS   = (0.0, 0.0),
                     (0.6, 0.0),
                     (0.75, 1.0),
                     (1.0, 1.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (0), BLUE (255);
        }
      }  /* LVAR */
      LVAR {
        NAME       = Reincidencia;
        BASEVAR    = Units;
        LVRANGE    = MIN(0.0), MAX(1.0),
                     MINDEF(0), MAXDEF(65535),
                     DEFAULT_OUTPUT(0.5);
        RESOLUTION = XGRID(0.1), YGRID(0.1),
                     SHOWGRID (ON), SNAPTOGRID(OFF);
        COLOR      = RED (0), GREEN (128), BLUE (0);
        INPUT      = CMBF;
        POS        = -168, -6;
        TERM {
          TERMNAME = Baixo;
          POINTS   = (0.0, 1.0),
                     (0.25, 1.0),
                     (0.6, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (255), GREEN (0), BLUE (0);
        }
        TERM {
          TERMNAME = Medio;
          POINTS   = (0.0, 0.0),
                     (0.4, 0.0),
                     (0.6, 1.0),
                     (0.8, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (128), BLUE (0);
        }
        TERM {
          TERMNAME = Alto;
          POINTS   = (0.0, 0.0),
                     (0.6, 0.0),
                     (0.75, 1.0),
                     (1.0, 1.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (0), BLUE (255);
        }
      }  /* LVAR */
      LVAR {
        NAME       = Veteranice;
        BASEVAR    = Units;
        LVRANGE    = MIN(0.0), MAX(1.0),
                     MINDEF(0), MAXDEF(65535),
                     DEFAULT_OUTPUT(0.5);
        RESOLUTION = XGRID(0.1), YGRID(0.1),
                     SHOWGRID (ON), SNAPTOGRID(OFF);
        COLOR      = RED (0), GREEN (0), BLUE (255);
        INPUT      = CMBF;
        POS        = -168, 168;
        TERM {
          TERMNAME = Baixo;
          POINTS   = (0.0, 1.0),
                     (0.3, 1.0),
                     (0.5, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (255), GREEN (0), BLUE (0);
        }
        TERM {
          TERMNAME = Medio;
          POINTS   = (0.0, 0.0),
                     (0.35, 0.0),
                     (0.55, 1.0),
                     (0.75, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (128), BLUE (0);
        }
        TERM {
          TERMNAME = Alto;
          POINTS   = (0.0, 0.0),
                     (0.6, 0.0),
                     (0.8, 1.0),
                     (1.0, 1.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (0), BLUE (255);
        }
      }  /* LVAR */
      LVAR {
        NAME       = Aceitacao;
        BASEVAR    = Units;
        LVRANGE    = MIN(0.0), MAX(1.0),
                     MINDEF(0), MAXDEF(65535),
                     DEFAULT_OUTPUT(0.5);
        RESOLUTION = XGRID(0.1), YGRID(0.1),
                     SHOWGRID (ON), SNAPTOGRID(OFF);
        COLOR      = RED (128), GREEN (0), BLUE (0);
        OUTPUT     = COM;
        POS        = 610, -5;
        TERM {
          TERMNAME = MuitoBaixo;
          POINTS   = (0.0, 1.0),
                     (0.16666, 1.0),
                     (0.33334, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (255), GREEN (0), BLUE (0);
        }
        TERM {
          TERMNAME = Baixo;
          POINTS   = (0.0, 0.0),
                     (0.16666, 0.0),
                     (0.33334, 1.0),
                     (0.5, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (128), BLUE (0);
        }
        TERM {
          TERMNAME = Medio;
          POINTS   = (0.0, 0.0),
                     (0.33334, 0.0),
                     (0.5, 1.0),
                     (0.66666, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (0), BLUE (255);
        }
        TERM {
          TERMNAME = Alto;
          POINTS   = (0.0, 0.0),
                     (0.5, 0.0),
                     (0.66666, 1.0),
                     (0.83334, 0.0),
                     (1.0, 0.0);
          SHAPE    = LINEAR;
          COLOR    = RED (128), GREEN (0), BLUE (0);
        }
        TERM {
          TERMNAME = MuitoAlto;
          POINTS   = (0.0, 0.0),
                     (0.66666, 0.0),
                     (0.83334, 1.0),
                     (1.0, 1.0);
          SHAPE    = LINEAR;
          COLOR    = RED (0), GREEN (128), BLUE (128);
        }
      }  /* LVAR */
    }  /* VARIABLE_SECTION */

    OBJECT_SECTION {
      RULEBLOCK {
        NAME        = RB1;
        INPUT       = Media, Reincidencia, Veteranice;
        OUTPUT      = Aceitacao;
        AGGREGATION = (MIN_MAX, PAR (0.0));
        RESULT_AGGR = MAX;
        POS         = 208, -18;
        RULES {
          IF    Media = Baixo
            AND Reincidencia = Baixo
            AND Veteranice = Baixo
          THEN  Aceitacao = MuitoBaixo   WITH 1.000;
          IF    Media = Baixo
            AND Reincidencia = Baixo
            AND Veteranice = Medio
          THEN  Aceitacao = MuitoBaixo   WITH 1.000;
          IF    Media = Baixo
            AND Reincidencia = Baixo
            AND Veteranice = Alto
          THEN  Aceitacao = Medio   WITH 1.000;
          IF    Media = Baixo
            AND Reincidencia = Medio
            AND Veteranice = Baixo
          THEN  Aceitacao = MuitoBaixo   WITH 1.000;
          IF    Media = Baixo
            AND Reincidencia = Medio
            AND Veteranice = Medio
          THEN  Aceitacao = Baixo   WITH 1.000;
          IF    Media = Baixo
            AND Reincidencia = Medio
            AND Veteranice = Alto
          THEN  Aceitacao = Alto   WITH 1.000;
          IF    Media = Baixo
            AND Reincidencia = Alto
            AND Veteranice = Baixo
          THEN  Aceitacao = Baixo   WITH 1.000;
          IF    Media = Baixo
            AND Reincidencia = Alto
            AND Veteranice = Medio
          THEN  Aceitacao = Medio   WITH 1.000;
          IF    Media = Baixo
            AND Reincidencia = Alto
            AND Veteranice = Alto
          THEN  Aceitacao = Alto   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Baixo
            AND Veteranice = Baixo
          THEN  Aceitacao = MuitoBaixo   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Baixo
            AND Veteranice = Medio
          THEN  Aceitacao = Baixo   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Baixo
            AND Veteranice = Alto
          THEN  Aceitacao = Medio   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Medio
            AND Veteranice = Baixo
          THEN  Aceitacao = Baixo   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Medio
            AND Veteranice = Medio
          THEN  Aceitacao = Medio   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Medio
            AND Veteranice = Alto
          THEN  Aceitacao = Alto   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Alto
            AND Veteranice = Baixo
          THEN  Aceitacao = Baixo   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Alto
            AND Veteranice = Medio
          THEN  Aceitacao = Medio   WITH 1.000;
          IF    Media = Medio
            AND Reincidencia = Alto
            AND Veteranice = Alto
          THEN  Aceitacao = Alto   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Baixo
            AND Veteranice = Baixo
          THEN  Aceitacao = Baixo   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Baixo
            AND Veteranice = Medio
          THEN  Aceitacao = Medio   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Baixo
            AND Veteranice = Alto
          THEN  Aceitacao = Alto   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Medio
            AND Veteranice = Baixo
          THEN  Aceitacao = Baixo   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Medio
            AND Veteranice = Medio
          THEN  Aceitacao = Alto   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Medio
            AND Veteranice = Alto
          THEN  Aceitacao = MuitoAlto   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Alto
            AND Veteranice = Baixo
          THEN  Aceitacao = Medio   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Alto
            AND Veteranice = Medio
          THEN  Aceitacao = Alto   WITH 1.000;
          IF    Media = Alto
            AND Reincidencia = Alto
            AND Veteranice = Alto
          THEN  Aceitacao = MuitoAlto   WITH 1.000;
        }  /* RULES */
      }  /* RULEBLOCK */
    }  /* OBJECT_SECTION */
  }  /* MODEL */
}  /* PROJECT */ 
/* fuzzyTECH 5.54d Professional Edition */
Ñ÷­ŒÏýiô
  ™ðÞ’“ÎÂ†™ = 20140903010808UT;
}  /* ONLINE */

NEUROFUZZY {
  LEARNRULE     =RandomMethod;
  STEPWIDTHDOS  = 0.100000;
  STEPWIDTHTERM = 1.000000;
  MAXDEVIATION  = (50.000000, 1.000000, 0.750000);
  AVGDEVIATION  = 0.100000;
  MAXSTEPS      = 100;
  NEURONS       = 1;
  DATASEQUENCE  = RANDOM;
  UPDATEDBGWIN  = OFF;
}  /* NEUROFUZZY */