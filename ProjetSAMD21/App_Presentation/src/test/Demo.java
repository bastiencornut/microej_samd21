/*
 * Java
 *
 * Copyright 2016 IS2T. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be found at http://www.microej.com/open-source-bsd-license/.
 */
package test;

import ej.microui.MicroUI;
import ej.microui.display.Colors;
import ej.microui.display.Display;
import ej.microui.display.Displayable;
import ej.microui.display.GraphicsContext;
import ej.microui.event.Event;
import ej.microui.event.EventGenerator;
import ej.microui.event.generator.Buttons;
import ej.microui.util.EventHandler;
import ej.microui.led.Leds;


public class Demo extends Displayable implements EventHandler {

	private int cpt;
	private int color;
	public static int bouton; //0 rien, 1 : ajout, 2 retrait
	public static boolean pressed;
	public static int cptLeds;


	public Demo(Display display) {
		super(display);
		this.color = Colors.WHITE;
	}

	private void HandleButton(int data) {

		String state = null;
		// print its state(s)
		if (Buttons.isPressed(data)) {
			state = "pressed ";
		}
		if (Buttons.isReleased(data)) {
			state = "released ";
			pressed = true; //Release after a pressed event
		}
		if (Buttons.isRepeated(data)) {
			state = "repeated ";
		}

		if (state != null) {
			System.out.print("button\t\t");

			// get the button's id
			int id = Buttons.getButtonID(data);
			System.out.print(id + " ");
			System.out.println(state);

			if(state == "pressed "){
				
				switch(id){
				case 0 :
					bouton = 0;
					break;
				case 1 :
					bouton = 1;
					break;
				case 2 :
					bouton = 2;
					break;
				case 3 :
					bouton = 3;
					break;
				}
			}
		}
	}
	
	@Override
	public void paint(GraphicsContext g) {	
		
		if(bouton==1){
			if(cptLeds<7){
				color = color == Colors.WHITE ? Colors.BLACK : Colors.WHITE;
				g.setColor(color);
				cptLeds += 1;
				cpt += 2;
				g.fillRect(cpt, cpt, g.getClipWidth() - cpt *2 , g.getClipHeight()-cpt*2);
			}
		}
		else if(bouton == 3){
			if(cptLeds>0){
				color = color == Colors.WHITE ? Colors.BLACK : Colors.WHITE;
				g.setColor(color);
				cptLeds -= 1;
				cpt -= 2;
				g.fillRect(cpt, cpt, g.getClipWidth() - cpt *2 , g.getClipHeight()-cpt*2);				
			}
		}
		else{
			cptLeds = 0;
			cpt =0;
			color = Colors.WHITE;
			g.setColor(Colors.WHITE);
			g.fillRect(0, 0, g.getClipWidth(), g.getClipHeight());	
			g.setColor(Colors.BLACK);
			g.drawString("DEMONSTRATION  APP", g.getClipWidth() / 2, g.getClipHeight() / 2, GraphicsContext.HCENTER | GraphicsContext.VCENTER);
		}
		switch(cptLeds){
			case 0:
				Leds.setLedOff(1);
				Leds.setLedOff(2);
				Leds.setLedOff(3);
				break;
			case 1:
				Leds.setLedOff(1);
				Leds.setLedOff(2);
				Leds.setLedOn(3);
				break;
				
			case 2:
				Leds.setLedOff(1);
				Leds.setLedOn(2);
				Leds.setLedOff(3);
				break;
				
			case 3:
				Leds.setLedOff(1);
				Leds.setLedOn(2);
				Leds.setLedOn(3);
				break;
				
			case 4:
				Leds.setLedOn(1);
				Leds.setLedOff(2);
				Leds.setLedOff(3);
				break;
			
			case 5:
				Leds.setLedOn(1);
				Leds.setLedOff(2);
				Leds.setLedOn(3);
				break;
				
			case 6:
				Leds.setLedOn(1);
				Leds.setLedOn(2);
				Leds.setLedOff(3);
				break;
				
			case 7:
				Leds.setLedOn(1);
				Leds.setLedOn(2);
				Leds.setLedOn(3);
				break;
		}

	}

	@Override
	public EventHandler getController() {
		return this;
	}

	
	@Override
	public boolean handleEvent(int event) {
		boolean eventProcessed = false;
		pressed = false;

		// Gets the event generator.
		final int genId = Event.getGeneratorID(event);
		EventGenerator gen;
		try {
			gen = EventGenerator.get(genId);
		} catch (IndexOutOfBoundsException e) {
			gen = null;
		}

		if (gen != null) {
			// Gets the type of event.
			final int type = Event.getType(event);
			int data = Event.getData(event);
			if (Event.BUTTON == type) {
				HandleButton(data);
			}		
			if(pressed) {
				System.out.println("Event pressed");
				eventProcessed = true;
			}
		}

		if (eventProcessed) {
			System.out.println("Repaint called");
			this.repaint();
		}
		return eventProcessed;
	}

	public static void main(String[] args) {
		// A call to MicroUI.start is required to initialize the graphics
		// runtime environment
		MicroUI.start();
		System.out.println("MicroUI started");

		final Display display = Display.getDefaultDisplay();

		Demo app = new Demo(display);
		bouton = 0;
		pressed = false;
		cptLeds = 0;
		app.show();
	}


}
