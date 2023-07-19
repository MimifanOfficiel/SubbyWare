#ifndef PRESETCONFIGURATIONS_HPP
#define PRESETCONFIGURATIONS_HPP

class PresetConfigurations {

private:
    int popupInterval;


public:
    inline PresetConfigurations(int interval) : popupInterval(interval) {}
    inline PresetConfigurations() : popupInterval(100) {}


    /* Getters */

    inline int getPopupInterval() { return popupInterval; }




    /* Setters */

    inline void setPopupInterval(int _interval) { popupInterval = _interval; }


};

#endif // PRESETCONFIGURATIONS_HPP
