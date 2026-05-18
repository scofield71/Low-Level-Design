package com.patterns.decorator.impl;

import com.patterns.decorator.interfaces.ICharacter;

public class Mario implements ICharacter {
    public String name;

    public Mario(String name) {
        this.name = name;
    }

    @Override
    public String getAbilities() {
        return name + " can run";
    }
}
