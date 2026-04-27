import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'Events';
  handleEvents(event:Event){
    console.log("Function called ",event.type);
    // console.log("Value of event ", (event.target as HTMLInputElement).value) //for input events
    // console.log("Event target ",(event.target as Element).className);
  }
}
