import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { LoginComponent } from './login/login.component';
import { SignupComponent } from './signup/signup.component';
import { ProfileComponent } from './profile/profile.component';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet,LoginComponent,SignupComponent,ProfileComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.scss'
})
export class AppComponent {
  name:string|number="Pranav";
  data:string|number="hello";
  other:any=true;

  updateName(){
    this.name=23;
    this.other="false";
  }
  // data = 2;
  // data2 = 2;
  // title = 'third';

  updateVar(){
    let x = 5;
  }

  sum(a:number,b:number){
    console.log(a+b);
  }
}
