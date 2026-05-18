package com.patterns.decorator.impl;

import com.patterns.decorator.interfaces.ICharacter;
import com.patterns.decorator.interfaces.IDecorator;

public class GunPowerDecorator implements IDecorator {
    public ICharacter character;

    public GunPowerDecorator(ICharacter c) {
        character = c;
    }
    @Override
    public String getAbilities() {
        return character.getAbilities() + " and have gun power";
    }
}
