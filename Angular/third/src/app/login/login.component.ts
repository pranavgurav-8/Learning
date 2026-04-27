import { Component } from '@angular/core';

@Component({
  selector: 'app-login',
  imports: [],
  templateUrl: './login.component.html',
  styleUrl: './login.component.scss'
})
export class LoginComponent {
  handleClickEvent(){
    alert("Login button clicked!");
    this.otherfunction();
  }
  otherfunction(){
    alert("other function called!");
  }
}
