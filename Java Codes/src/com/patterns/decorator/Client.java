package com.patterns.decorator;

import com.patterns.decorator.impl.GunPowerDecorator;
import com.patterns.decorator.impl.HeightUpDecorator;
import com.patterns.decorator.impl.Mario;
import com.patterns.decorator.impl.StarPowerDecorator;
import com.patterns.decorator.interfaces.ICharacter;

public class Client {
    public static void main(String[] args) {
        ICharacter mario = new Mario("Vanshu");
        System.out.println(mario.getAbilities());
        System.out.println(new HeightUpDecorator(mario).getAbilities());
        System.out.println(new GunPowerDecorator(new HeightUpDecorator(mario)).getAbilities());
        System.out.println(new StarPowerDecorator(new GunPowerDecorator(new HeightUpDecorator(mario))).getAbilities());

    }
}
