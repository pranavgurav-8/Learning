import { Component } from '@angular/core';

@Component({
    selector: 'app-profile',
    // template:"<h1>Profile</h1>",
    templateUrl: './profile.component.html',
    // styles: "h1{color:green}"
    styleUrls: ['./profile.component.css']
})
export class ProfileComponent {
  constructor() {
    console.log('ProfileComponent initialized');
  }
}