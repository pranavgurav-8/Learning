import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'InputField';
  name="";
  displayName="";
  email=""
  getName(event:Event){
    const name = (event.target as HTMLInputElement).value;

    this.name = name;
    console.log(name);
  }

  showName(){
    this.displayName = this.name;
    console.log(this.displayName);
  }

  setName(){
    this.name = "Default Name";
  }

  getEmail(val:string){
    console.log(val);
    this.email=val;
  }

  setEmail(){

  }
}
