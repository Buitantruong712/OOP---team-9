    #pragma once
    #include "Support.h"

    class Setting {
    private:
        string language[2][5];

        bool chosenLanguage;
        bool sound;
    public:
        // Constructor
        Setting();

        // Some feature
        void TurnOnMusic();
        void TurnOffMusic();
        void English();
        void VietNamese();

        // Get status
        bool MusicStatus();
        bool LanguageStatus();
        string getLanguage(int);

        // Draw Setting
        void drawSetting();

        // Control choosing
        void settingChosing();
    };