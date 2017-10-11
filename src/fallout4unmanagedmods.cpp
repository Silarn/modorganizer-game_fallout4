#include "game_fallout4/fallout4unmanagedmods.h"

Fallout4UnmangedMods::Fallout4UnmangedMods(const GameGamebryo* game) : GamebryoUnmangedMods(game) {}

Fallout4UnmangedMods::~Fallout4UnmangedMods() {}

QStringList Fallout4UnmangedMods::secondaryFiles(const QString& modName) const {
    // file extension in FO4 is .ba2 instead of bsa
    QStringList archives;
    QDir dataDir = game()->dataDirectory();
    for (const QString& archiveName : dataDir.entryList({modName + "*.ba2"})) {
        archives.append(dataDir.absoluteFilePath(archiveName));
    }
    return archives;
}

QString Fallout4UnmangedMods::displayName(const QString& modName) const {
    // unlike in earlier games, in fallout 4 the file name doesn't correspond to
    // the public name
    if (modName.compare("dlcrobot", Qt::CaseInsensitive) == 0) {
        return "Automatron";
    } else if (modName.compare("dlcworkshop01", Qt::CaseInsensitive) == 0) {
        return "Wasteland Workshop";
    } else if (modName.compare("dlccoast", Qt::CaseInsensitive) == 0) {
        return "Far Harbor";
    } else if (modName.compare("dlcworkshop02", Qt::CaseInsensitive) == 0) {
        return "Contraptions Workshop";
    } else if (modName.compare("dlcworkshop03", Qt::CaseInsensitive) == 0) {
        return "Vault-Tec Workshop";
    } else if (modName.compare("dlcnukaworld", Qt::CaseInsensitive) == 0) {
        return "Nuka-World";
    } else {
        return modName;
    }
}
