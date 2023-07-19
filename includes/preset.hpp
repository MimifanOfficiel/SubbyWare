#ifndef PRESET_HPP
#define PRESET_HPP

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

#include "presetConfigurations.hpp"

class Preset {

private:
    QString name, description, dirLocation, category, domType, domName;
    PresetConfigurations *config;


public:
    inline Preset() {}
    inline Preset(QString _name, QString _dirLocation, QString _category, QString _domType) : name(_name), dirLocation(_dirLocation), category(_category), domType(_domType), config(new PresetConfigurations()) {}
    inline Preset(QString _name, QString desc, QString _dirLocation, QString _category, QString _domType, QString _domName) : name(_name), description(desc), dirLocation(_dirLocation), category(_category), domType(_domType), domName(_domName), config(new PresetConfigurations()) {}

    Preset(QString _name, QString _dirLocation, QString _category, QString _domType, QString descOrDomName, bool isDesc);

    /* Getters */

    inline const QString getName()            const { return name; }
    inline const QString getDescription()     const { return description; }
    inline const QString getCategory()        const { return category; }
    inline const QString getLocation()        const { return dirLocation; }
    inline const QString getDomType()         const { return domType; }
    inline const QString getDomName()         const { return domName; }

    inline PresetConfigurations* getConfig()         { return config; }

    /* Setters */

    inline void setName(QString _name)            { name = _name; }
    inline void setDescription(QString desc)      { description = desc; }
    inline void setCategory(QString _category)    { category = _category; }
    inline void setLocation(QString _dirLocation) { dirLocation = _dirLocation; }
    inline void setDomName(QString _name)         { domName = _name; }
    inline void setDomType(QString _type)         { domType = _type; }

    inline void setConfig(PresetConfigurations *_config) { config = _config; }


    QJsonDocument toJSON();

};

#endif // PRESET_HPP
