import { Component } from '@angular/core';
import { Router, RouterLink } from '@angular/router';

@Component({
  selector: 'app-home',
  imports: [RouterLink],
  templateUrl: './home.component.html',
  styleUrl: './home.component.css'
})
export class HomeComponent {
  constructor(private router: Router) {}
  // gotoProfile(name:string) {
  //   // Navigate to the profile page with a parameter
  //   this.router.navigate(['profile'], {queryParams:{ name: name }});
  //   // For now, we will just log the action
  //   console.log('Navigating to profile page');
  // }
}
