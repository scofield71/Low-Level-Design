package com.patterns.observer.impl;

import com.patterns.observer.interfaces.IObservable;
import com.patterns.observer.interfaces.IObserver;

public class ConcreteObserver implements IObserver {
    public String name;
    private ConcreteObservable observable;
    @Override
    public void update() {
        String updatedAsset = observable.getValue();
        System.out.println("Latest asset received by " + getName() + " : " + updatedAsset);
    }

    @Override
    public String getName() {
        return this.name;
    }

    public ConcreteObserver(String observerName, ConcreteObservable ol) {
        name = observerName;
        observable = ol;
    }
}
