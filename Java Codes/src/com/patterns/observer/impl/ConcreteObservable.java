package com.patterns.observer.impl;

import com.patterns.observer.interfaces.IObservable;
import com.patterns.observer.interfaces.IObserver;

import java.util.ArrayList;

public class ConcreteObservable implements IObservable {
    private final ArrayList<IObserver> observers;

    public ConcreteObservable() {
        observers = new ArrayList<>();
    }

    @Override
    public void addObserver(IObserver observer) {
        Boolean exists = this.observers.stream().
                anyMatch(ob -> ob.getName().compareToIgnoreCase(observer.getName())==0);
        if(!exists) {
            observers.add(observer);
            System.out.println("Added observer");
        } else System.out.println("Observer already exists");
    }

    @Override
    public void removeObserver(IObserver observer) {
        int index = -1;
        for(int i=0;i<this.observers.size();i++) {
            if(this.observers.get(i).getName().equalsIgnoreCase(observer.getName())) {
                index = i;
                break;
            }
        }
        if(index!=-1) {
            this.observers.remove(index);
            System.out.println("Observer with name " + observer.getName() + " is removed");
        } else System.out.println("Observer does not exists");
    }

    @Override
    public void triggerNotification() {
        for(IObserver observer : observers) {
            observer.update();
        }
    }

    public String getValue() {
        return "Spiderman-1.4.5";
    }
}
